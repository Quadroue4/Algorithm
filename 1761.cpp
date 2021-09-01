//1761.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int parent[40001];
int cost[40001];
vector<pair<int,int>> informations[40001];
bool used[40001];

int common_parent(int a,int b){
    vector<int> stack;
    int sum=0;
    int subroot = 0;
    int temp = a;
    while(a!=1){
        used[a] = true;
        stack.push_back(a);
        a = parent[a];
    }

    while(b!=1){
        if(used[b]){
            subroot = b;
            break;
        }
        sum += cost[b];
        b = parent[b];
    }

    while(temp!=subroot && temp != 1){
        sum += cost[temp];
        temp = parent[temp];
    }
    for(int i=0;i<stack.size();i++){
        used[stack[i]] = false;
    }
    return sum;
}

bool have_parent(int a){
    return parent[a] != 0;
}

void joint_node(int a,int b,int c){
    if(have_parent(a)){
        parent[b] = a;
        cost[b] = c;
    }
    else{
        parent[a] = b;
        cost[a] = c;
    }
}

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first < b.first;
}

void dfs(int a){
    //sort(informations[a].begin(),informations[a].end(),cmp);
    for(int i=0;i<informations[a].size();i++){
        int temp = informations[a][i].first;
        int cost = informations[a][i].second;
        if(!have_parent(temp)){
            joint_node(a,temp,cost);
            dfs(temp);
        }
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N-1;i++){
        int s,e,c;
        scanf("%d %d %d",&s,&e,&c);
        informations[min(s,e)].push_back({max(s,e),c});
        informations[max(s,e)].push_back({min(s,e),c});
    }

    parent[1] = 1;//1을 루트로 설정.

    dfs(1);

    scanf("%d",&M);
    for(int i=0;i<M;i++){
        int s,e;
        scanf("%d %d",&s,&e);
        cout<<common_parent(s,e)<<"\n";
    }
}