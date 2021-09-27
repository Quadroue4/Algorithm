//2533.cpp

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> graph[1000001];
bool visited[1000001];
int ans;

bool is_leaf(int node){
    visited[node] = true;
    int count = 0;
    for(int i=0;i<graph[node].size();i++){
        if(!visited[graph[node][i]])
            count++;
    }
    if(count == 0)
        return true;
    int judge = false;
    for(int i=0;i<graph[node].size();i++){
        if(!visited[graph[node][i]]){
            judge |= is_leaf(graph[node][i]);
        }
    }
    if(judge){
        ans++;
        return false;
    }
    return true;
}
int main(){
    scanf("%d",&N);
    int a,b;
    for(int i=0;i<N-1;i++){
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);

    }

    is_leaf(1);

    cout<<ans;

}