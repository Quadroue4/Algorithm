//11438.cpp

#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<int> graph[100001];
int parent[100001][18];
int depth[100001];
bool visited[100001];

void dfs(int current,int ancestor,int dep){
    if(visited[current])
        return;
    visited[current] = true;
    parent[current][0] = ancestor;
    depth[current] = dep;
    for(int i=0;i<graph[current].size();i++){
        int next = graph[current][i];
        dfs(next,current,dep+1);
    }
}

void init(){
    dfs(1,1,0);

    for(int bit=1;bit<=17;bit++){
        for(int node = 1;node<=N;node++){
            int next = parent[node][bit-1];
            parent[node][bit] = parent[next][bit-1];
        }
    }
}

int query(int a,int b){
    if(depth[a] > depth[b]){
        int temp = b;
        b = a;
        a = temp;
    }

    for(int i=17;i>=0;i--){
        if(depth[b]-depth[a] >= 1<<i ){
            b = parent[b][i];
        }
    }

    if(a == b)
        return a;

    for(int i=17;i>=0;i--){
        if(parent[a][i] != parent[b][i]){
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

int main(){
    cin >> N;
    int a,b;
    for(int i=0;i<N-1;i++){
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    init();

    cin >> M;
    for(int i=0;i<M;i++){
        scanf("%d %d",&a,&b);
        cout<<query(a,b)<<"\n";
    }

}