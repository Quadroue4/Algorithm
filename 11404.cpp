#include <iostream>

using namespace std;

int city_to_city[100][100];
int n,m;

void optimal_cost(int k){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j || i == k || j == k)
                continue;
            if(city_to_city[i][k] == 0 || city_to_city[k][j] == 0)
                continue;
            int temp = city_to_city[i][j];
            int temp2 = city_to_city[i][k] + city_to_city[k][j];
            if(temp == 0 || temp2 < temp)
                city_to_city[i][j] = temp2;
        }
    }
}
void show(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << city_to_city[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(city_to_city[a-1][b-1] != 0){
            city_to_city[a-1][b-1] = city_to_city[a-1][b-1] < c ? city_to_city[a-1][b-1] : c;
        }
        else
            city_to_city[a-1][b-1] = c;
    }
    //show();

    for(int i=0;i<n;i++){
        optimal_cost(i);
    }
    show();
}