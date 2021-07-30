//1197.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[10000];

/*
bool compare(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
    if(a.first > b.first)
        return false;
    else
        return true;
}
*/

bool compare(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
    if(a.first < b.first)
        return true;
    else
        return false;
}

int getParent(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = getParent(parent[x]);
}

void mergeGraph(int x,int y){
    int xP = getParent(x);
    int yP = getParent(y);
    if(xP<yP){
        parent[yP] = xP;
    }
    else if(xP>yP)
        parent[xP] = yP;
}

int main(){
    int V,E,sum=0,count=0,idx = 0;
    vector<pair<int,pair<int,int>>> graph; // {cost,{node,node}}

    cin >> V >> E;

    for(int i=0;i<10000;i++)
        parent[i] = i;

    for(int i=0;i<E;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph.push_back({c,{a-1,b-1}});
    }

    //sort(graph.begin(),graph.end());

    sort(graph.begin(),graph.end(),compare);

    while(idx < E){
        auto temp = graph[idx++];
        int cost = temp.first;
        pair<int,int> nodes = temp.second;
        int node1 = nodes.first;
        int node2 = nodes.second;
        if(getParent(node1) == getParent(node2)){
            continue;
        }
        mergeGraph(node1,node2);
        count++;
        sum += cost;
    }
    cout<<sum;
}