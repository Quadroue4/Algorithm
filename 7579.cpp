//7579.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cost[10001];
bool used[10001];

int main(){
    int N,M;
    vector<pair<int,int>> programs; // {cost,memory}
    cin >> N >> M;
    int a;
    for(int i=0;i<N;i++){
        cin >> a;
        programs.push_back({0,a});
    }
    for(int i=0;i<N;i++){
        cin >> a;
        programs[i].first = a;
    }

    sort(programs.begin(),programs.end());

    int maxi = 0;
    used[0] = true;
    for(int i=0;i<programs.size();i++){
        //cout<<"what we used "<<programs[i].first<<" "<<programs[i].second<<" "<<maxi<<"\n";
        for(int j=maxi;j>=0;j--){
            if(used[j]){
                cost[j+programs[i].first] = max(cost[j+programs[i].first],cost[j]+programs[i].second);
                used[j+programs[i].first] = true;
                //cout<<j+programs[i].first<<" "<<cost[j+programs[i].first]<<"\n";
            }
            //cout<<"-----------------\n";
        }
        //cout<<"-------------------------------------\n";
        maxi += programs[i].first;
        //maxi = temp;
    }

    for(int i=0;i<=maxi;i++){
        //cout<<cost[i]<<" ";
        if(cost[i] >= M){
            cout<<i;
            break;
        }
    }
}