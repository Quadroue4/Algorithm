//11266.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[10001];
vector<int> dfs_graph[10001];
int min_ancestor[10001];
int back_edge[10001];
bool visit[10001];
bool is_root[10001];
int node_order[10001];
int node_num;
int sub_root_count[10001];
int V,E;
vector<int> ans_nodes;

void dfs(int current,int ancestor,int root){
    if(visit[current])
        return;
    dfs_graph[ancestor].push_back(current);

    node_order[current] = node_num++;
    visit[current] = true;
    if(current != root && ancestor == root){
        sub_root_count[root]++;
    }

    back_edge[current] = ancestor;

    for(int i=0;i<graph[current].size();i++){
        dfs(graph[current][i],current,root);
    }
}

int get_min_ancestor(int current){
    if(visit[current])
        return min_ancestor[current];
    visit[current] = true;
    min_ancestor[current] = current;
    int back = back_edge[current];
    for(int i=0;i<graph[current].size();i++){
        int next = graph[current][i];
        if(next == back)
            continue;
        if(node_order[next] < node_order[min_ancestor[current]]){
            min_ancestor[current] = next;
            continue;
        }

        int temp = get_min_ancestor(next);

        if(node_order[temp] < node_order[min_ancestor[current]])
            min_ancestor[current] = temp;
    }
    return min_ancestor[current];
}

int main(){
    scanf("%d %d",&V,&E);

    int s,e;
    for(int i=0;i<E;i++){
        scanf("%d %d",&s,&e);
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    
    for(int i=1;i<=V;i++){
        if(visit[i])
            continue;
        is_root[i] = true;
        dfs(i,i,i);
    }

    for(int i=1;i<=V;i++)
        visit[i] = false;

    for(int i=1;i<=V;i++){
        if(visit[i])
            continue;
        get_min_ancestor(i);
    }

    for(int i=1;i<=V;i++){
        int back = back_edge[i];
        if(is_root[i]){
            if(sub_root_count[i] > 1){
                ans_nodes.push_back(i);
            }
            continue;
        }
        bool judge = false;
        for(int j=0;j<dfs_graph[i].size();j++){
            int next = dfs_graph[i][j];
            if( node_order[i] <= node_order[min_ancestor[next]] ){
                judge = true;
                break;
            }
        }
        if(judge){
            ans_nodes.push_back(i);
        }
    }
    sort(ans_nodes.begin(),ans_nodes.end());
    cout<<ans_nodes.size()<<"\n";
    for(int i=0;i<ans_nodes.size();i++){
        cout<<ans_nodes[i]<<" ";
    }

}