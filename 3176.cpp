//3176.cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,K;
vector<pair<int,int>> graph[100001];
int ancestor[100001][20];
int max_distance[100001][20];
int min_distance[100001][20];
bool visited[100001];
int depth[100001];

void init(int node,int dep){
    visited[node] = true;
    depth[node] = dep;
    for(int i=0;i<graph[node].size();i++){
        int next = graph[node][i].first;
        int cost = graph[node][i].second;
        if(visited[next])
            continue;
        ancestor[next][0] = node;
        max_distance[next][0] = cost;
        min_distance[next][0] = cost;
        init(next,dep+1);
    }
}

void make_dp(){
    for(int i=1;i<=19;i++){
        for(int node = 1; node <= N; node++){
            int next = ancestor[node][i-1];
            ancestor[node][i] = ancestor[next][i-1];
            max_distance[node][i] = max(max_distance[node][i-1],max_distance[next][i-1]);
            min_distance[node][i] = min(min_distance[node][i-1],min_distance[next][i-1]);
        }
    }
}

void query(int a,int b){
    if(depth[a] > depth[b]){
        int temp = b;
        b = a;
        a = temp;
    }
    int maxi = 0;
    int mini = 1000001;
    // 이제 depth는 무조건 a <= b
    int idx = 0;
    while(depth[a] < depth[b]){
        idx = 0;
        while(depth[a] < depth[ancestor[b][idx+1]]){
            idx++;
        }
        maxi = max(maxi,max_distance[b][idx]);
        mini = min(mini,min_distance[b][idx]);
        b = ancestor[b][idx];
    }
    while(a != b){
        idx = 0;
        while(ancestor[a][idx+1] != ancestor[b][idx+1]){
            idx++;
        }//이러면 idx+1만큼 점프하면 무조건 같겠지만, 최소는 아닐수 있음. 그렇기에 같기 바로전 까지만 점프
        maxi = max(maxi,max_distance[a][idx]);
        maxi = max(maxi,max_distance[b][idx]);

        mini = min(mini,min_distance[a][idx]);
        mini = min(mini,min_distance[b][idx]);

        a = ancestor[a][idx];
        b = ancestor[b][idx];
    }
    cout<<mini<<" "<<maxi<<"\n";
}

int main(){
    scanf("%d",&N);
    int a,b,c;
    for(int i=0;i<N-1;i++){
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    ancestor[1][0] = 0;
    max_distance[1][0] = 0;
    min_distance[1][0] = 1000001;
    init(1,0);
    make_dp();

    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d %d",&a,&b);
        query(a,b);
    }
}