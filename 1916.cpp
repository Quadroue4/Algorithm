#include <iostream>
#include <queue>

using namespace std;

long bus_cost[1001][1001];
bool isVisited[1001];
long city_cost[1001];
struct cmp{
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second > b.second;
    }
};
int main(){
    for(int i=0;i<1001;i++){
        isVisited[i] = false;
        for(int j=0;j<1001;j++)
            bus_cost[i][j] = -1;
    }
    int N;
    int M;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >> b>> c;
        if(bus_cost[a][b] == -1 || bus_cost[a][b] > c)
            bus_cost[a][b] = c;
    }
    int start,end;
    cin >> start>>end;
    priority_queue<pair<int,long>,vector<pair<int,long>>,cmp> pq; //노드번호 , 시작점부터 해당 노드까지의 길이
    pq.push({start,0});
    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();
        int node = temp.first;
        long cost = temp.second;
        if(!isVisited[node]){
            isVisited[node] = true;
            city_cost[node] = cost;
            for(int i=1;i<=N;i++){
                if(node != i && bus_cost[node][i] != -1){
                    pq.push({i,cost+bus_cost[node][i]});
                }
            
            }
        }

    }

    cout << city_cost[end];
}