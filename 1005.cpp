#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T,N,K,W;
int delay[1001];
int total_dealy[1001];
bool building_connection[1001][1001]; // 공사 순서가 B -> C 라면, building_connection[C][B] = true 가 나와야 한다.

struct cmp{
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second <= b.second; //큰친구 먼저 확인하도록.
    }
};

int dijkstra(int w){
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    pq.push({w,delay[w]});
    fill(total_dealy,total_dealy+1001,-1);
    while(!pq.empty()){
        pair<int,int> temp = pq.top();
        pq.pop();
        int node = temp.first;
        int cost = temp.second;
        if(total_dealy[node] > cost)
            continue;
        total_dealy[node] = cost;
        for(int i=1;i<=N;i++){
            if(building_connection[node][i]){
                pq.push({i,cost+delay[i]});
            }
        }
    }
    int max_dis = 0;
    for(int i=1;i<=N;i++){
        int temp = total_dealy[i];
        if(temp > max_dis)
            max_dis = temp;
    }
    return max_dis;
}

int main(){
    vector<int> ans;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> N >> K;

        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                building_connection[i][j] = false;

        for(int j=1;j<=N;j++){
            cin >> delay[j];
        }
        for(int j=0;j<K;j++){
            int a,b,w;
            cin >> a >> b;
            building_connection[b][a] = true;
        }
        cin >> W;
        cout<<dijkstra(W)<<"\n";
    }
}