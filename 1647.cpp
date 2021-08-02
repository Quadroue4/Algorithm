//1647.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[100001];

int get_Parent(int x){
    if(x == parent[x])
        return x;
    return parent[x] = get_Parent(parent[x]);
}

bool merge(int x,int y){
    int xP = get_Parent(x);
    int yP = get_Parent(y);
    if(xP == yP)
        return false;
    parent[max(xP,yP)] = min(xP,yP);
    return true;
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<pair<int,pair<int,int>>> way;
    for(int i=1;i<=N;i++)
        parent[i] = i;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;
        way.push_back({c,{a,b}});
    }
    sort(way.begin(),way.end());

    vector<int> cost;

    int j = 0;
    while(cost.size() < N-1){
        pair<int,pair<int,int>> temp = way[j++];
        if(merge(temp.second.first,temp.second.second))
            cost.push_back(temp.first);
    }

    long long sum  = 0;
    for(int i=0;i<N-2;i++)
        sum += cost[i];

    cout<<sum;
}