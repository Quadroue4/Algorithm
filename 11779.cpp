#include <iostream>
#include <queue>

using namespace std;

long bus_cost[1001][1001];
bool isVisited[1001];
long city_cost[1001];
int visitFrom[1001];
struct cmp{
    bool operator()(pair<int,pair<int,long>> a,pair<int,pair<int,long>> b){
        return a.second.second > b.second.second;
    }
};
int main(){
    for(int i=0;i<1001;i++){
        isVisited[i] = false;
        city_cost[i] = -1;
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
    priority_queue<pair<int,pair<int,long>>,vector<pair<int,pair<int,long>>>,cmp> pq; //노드번호 , 시작점부터 해당 노드까지의 길이
    pq.push({0,{start,0}});
    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();
        int temp1 = temp.first;
        auto temp2 = temp.second;
        int node = temp2.first;
        long cost = temp2.second;
        if(!isVisited[node]){
            isVisited[node] = true;
            city_cost[node] = cost;
            visitFrom[node] = temp1;
            for(int i=1;i<=N;i++){
                if(node != i && bus_cost[node][i] != -1){
                    pq.push({node,{i,cost+bus_cost[node][i]}});
                }
            
            }
        }

    }
    int point1 = end;
    int count = 1;
    vector<int> path;
    path.push_back(point1);
    while(point1 != start){
        point1 = visitFrom[point1];
        path.push_back(point1);
        count++;
    }
    cout << city_cost[end]<<endl;
    cout << count<<endl;
    for(auto it=path.rbegin();it<path.rend();it++)
        cout<<*it<<" ";
}