#include <iostream>
#include <vector>

using namespace std;

int N,M;
int Map[50][50];

vector<pair<int,int>> house;
vector<pair<int,int>> chickens;
vector<vector<bool>> close_comb;

int chicken_dis(pair<int,int> a, pair<int,int> b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int closed_number(vector<bool> chick){
    int count = 0;
    for(int i=0;i<chick.size();i++)
        if(chick[i] == true)
            count++;

    return count;
}
void combination(vector<bool>& temp_chick,int count){ // chickens.size()중에 m개를 고르는데, 모든 경우의 수 false면 폐업하는곳이라 하자.
    if(0 == chickens.size()-M){
        close_comb.push_back(temp_chick);
        return;
    }
    if(count != -1){
        temp_chick[count] = true;
        if(closed_number(temp_chick) == chickens.size()-M){
            close_comb.push_back(temp_chick);
            temp_chick[count] = false;
            return;
        }
    }
    for(int i=count+1;i<chickens.size();i++){
        combination(temp_chick,i);
    }
    if(count != -1)
        temp_chick[count] = false;
}

int city_chicken_dis(int n){
    int dis_sum = 0;
    vector<bool> closed_chick = close_comb[n];
    for(int i=0;i<house.size();i++){
        int min_dis = 9999999;
        for(int j=0;j<chickens.size();j++){
            if(closed_chick[j])
                continue;

            int dis = chicken_dis(house[i],chickens[j]);
            if(dis < min_dis)
                min_dis = dis;
        }
        dis_sum += min_dis;
    }
    return dis_sum;
}
int main(){
    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int a;
            cin >> a;
            Map[i][j] = a;
            if(a == 1)
                house.push_back({i,j});
            else if(a==2)
                chickens.push_back({i,j});
        }
    }

    int min_dis = 9999999;
    vector<bool> closed_chicks;
    for(int i=0;i<chickens.size();i++)
        closed_chicks.push_back(false);

    combination(closed_chicks,-1);

/*
    cout<<close_comb.size()<<"\n";
    for(int i=0;i<close_comb.size();i++){
        for(int j=0;j<close_comb[i].size();j++){
            cout<<close_comb[i][j]<<" ";
        }
        cout<<"\n";
    }
*/
    for(int i=0;i< close_comb.size();i++){
        int temp = city_chicken_dis(i);
        if(temp < min_dis)
            min_dis = temp;
    }
    cout<<min_dis;
}