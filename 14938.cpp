#include <iostream>

using namespace std;

int n,m,r;
int item[100];
int location_graph[100][100];

int optimal_cost(int k){
    int sum = 0;
    for(int i=0;i<n;i++){
        if(i == k || (location_graph[k][i] != 0 && location_graph[k][i] <= m)){
            sum += item[i];
        }
    }
    return sum;
}

void show(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << location_graph[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    cin >> n >> m >> r;
    for(int i=0;i<n;i++){
        cin >> item[i];
    }
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            location_graph[i][j] = 0;

    for(int i=0;i<r;i++){
        int a,b,c;
        cin >> a >> b >>c;
        if(location_graph[a-1][b-1] > c){
            location_graph[a-1][b-1] = c;
            location_graph[b-1][a-1] = c;
        }
        else if(location_graph[a-1][b-1] == 0){
            location_graph[a-1][b-1] = c;
            location_graph[b-1][a-1] = c;
        }
    }
    
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i == j || i == k || j == k || location_graph[i][k] == 0 || location_graph[k][j] == 0)
                    continue;
                int temp = location_graph[i][j];
                int temp2 = location_graph[i][k] + location_graph[k][j];
                if(temp==0 || temp2 < temp){
                    location_graph[i][j] = temp2;
                    location_graph[j][i] = temp2;
                }
            }
        }
    }
    
    int ans = 0;
    for(int i=0;i<n;i++){
        int temp = optimal_cost(i);
        if(temp > ans)
            ans = temp;
    }
    //show();
    cout<<ans;
}