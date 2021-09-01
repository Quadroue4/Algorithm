//1948.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int topological_follower[10001];
queue<int> tq;
vector<pair<int,int>> topological_following[10001];
int total_cost[10001];
vector<int> back_follower[10001];
bool used[10001];
int N,M;
int S,E;

int main(){
    scanf("%d",&N);
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        int s,e,c;
        scanf("%d %d %d",&s,&e,&c);
        topological_follower[e]++;
        topological_following[s].push_back({e,c});
    }

    for(int i=1;i<=N;i++){
        if(topological_follower[i] == 0){
            tq.push(i);
        }
    }

    scanf("%d %d",&S,&E);

    while(!tq.empty()){
        int temp = tq.front();
        tq.pop();
        for(int i=0;i<topological_following[temp].size();i++){
            int temp2 = topological_following[temp][i].first;
            int cost = topological_following[temp][i].second;
            if(total_cost[temp2] < total_cost[temp]+cost){
                total_cost[temp2] = total_cost[temp]+cost;
                back_follower[temp2].clear();
                back_follower[temp2].push_back(temp);
            }
            else if(total_cost[temp2] == total_cost[temp]+cost){
                back_follower[temp2].push_back(temp);
            }
            topological_follower[temp2]--;
            if(topological_follower[temp2] == 0){
                tq.push(temp2);
            }
        }

    }

    cout<<total_cost[E]<<"\n";

    queue<int> q;
    q.push(E);
    int ans = 0;
    while(!q.empty()){
        int follower = q.front();
        q.pop();
        if(used[follower])
            continue;
        used[follower] = true;
        for(int i=0;i<back_follower[follower].size();i++){
            q.push(back_follower[follower][i]);
            ans++;
        }
    }
    cout<<ans;
}