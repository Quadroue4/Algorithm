//3648.cpp

#include <iostream>
#define participant 1000
using namespace std;

bool graph[2000][2000]; // false면 idx+participant로 index 참조
int info[1000];
int n,m;
bool visited[2000];

void init(int m){
    for(int i=1;i<=m;i++){
        info[i] = 0;
        visited[i] = false;
        for(int j=1;j<=m;j++)
            graph[i][j] = false;
    }
}

bool can_put_on_info(int player){
    int idx = player < participant ? player : player-participant;
    int value = player < participant ? 1 : -1;
    if(info[idx] != 0){
        return info[idx] == value;
    }
    info[idx] = value;
    return true;
}

bool dfs(int current){
    if(visited[current])
        return true;
    
    int other = current < participant ? current+participant : current-participant;
    if(visited[other])
        return false;

    visited[current] = true;
    for(int i=1;i<=n+participant;i++){
        if(graph[current][i]){
            if(!dfs(i)) return false;
        }
    }
    return true;
}

void solve(){
    if(dfs(1))
        cout<<"yes\n";
    else
        cout<<"no\n";
}

int main(){
    int a,b;
    while(scanf("%d %d",&n,&m)){
        init(n);
        for(int i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            if(a>0){
                if(b>0){
                    graph[a+participant][b] = true;
                    graph[b+participant][a] = true;
                }
                else if(b<0){
                    graph[a+participant][-1*b+participant] = true;
                    graph[-1*b][a] = true;
                }
            }
            else if(a<0){
                if(b>0){
                    graph[-1*a][b] = true;
                    graph[b+participant][-1*a+participant] = true;
                }
                else if(b<0){
                    graph[-1*a][-1*b+participant] = true;
                    graph[-1*b][-1*a+participant] = true;
                }
            }
        }
        solve();
    }
}