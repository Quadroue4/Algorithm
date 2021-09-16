//2150.cpp

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int V,E;
vector<int> graph[10001];
vector<int> reverse_graph[10001];
stack<int> node_stack;
bool visit[10001];
int group_idx[10001];//그룹은 1부터 시작.
vector<vector<int>> groups;
int group_count;

void dfs(int node){
    if(visit[node])
        return;
    visit[node] = true;
    for(int i=0;i<graph[node].size();i++){
        dfs(graph[node][i]);
    }
    node_stack.push(node);
}

void make_group(int node){
    groups[group_count].push_back(node);
    for(int i=0;i<reverse_graph[node].size();i++){
        int next = reverse_graph[node][i];
        if(group_idx[next] > 0)
            continue;
        group_idx[next] = group_idx[node];
        make_group(next);
    }
}

int main(){
    scanf("%d %d",&V,&E);
    int s,e;
    for(int i=0;i<E;i++){
        scanf("%d %d",&s,&e);
        graph[s].push_back(e);
        reverse_graph[e].push_back(s);
    }

    for(int i=1;i<=V;i++){
        dfs(i);
    }

    group_count = 0;

    while(node_stack.size()>0){
        int node = node_stack.top();
        node_stack.pop();
        if(group_idx[node] > 0)
            continue;
        vector<int> temp;
        groups.push_back(temp);
        group_idx[node] = node;
        make_group(node);
        sort(groups[group_count].begin(),groups[group_count].end());
        groups[group_count].push_back(-1);
        group_count++;
    }
    sort(groups.begin(),groups.end());

    cout<<groups.size()<<"\n";

    for(int i=0;i<groups.size();i++){
        for(int j=0;j<groups[i].size();j++){
            cout<<groups[i][j]<<" ";
        }
        cout<<"\n";
    }
}