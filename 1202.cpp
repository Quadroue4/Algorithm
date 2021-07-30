//1202.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
    if(a.first < b.first)
        return true;
    else if(a.first == b.first && a.second > b.second)
        return true;
    return false;
}

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.second < b.second)
            return true;
        else
            return false;
    }
};

int main(){
    int N,K;
    cin >> N >> K;

    vector<pair<int,int>> jewel;
    vector<int> backpack;
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;

    for(int i=0;i<N;i++){
        int M,V;
        cin >> M >> V;
        jewel.push_back({M,V});
    }
    for(int i=0;i<K;i++){
        int C;
        cin >> C;
        backpack.push_back(C);
    }
    sort(jewel.begin(),jewel.end());
    sort(backpack.begin(),backpack.end());


    int idx = 0;
    long long total_value = 0;
    for(int i=0;i<backpack.size();i++){
        int weight = backpack[i];
        while(jewel[idx].first <= weight && idx < jewel.size()){
            pq.push(jewel[idx++]);
        }
        if(pq.empty())
            continue;
        pair<int,int> temp = pq.top();
        pq.pop();
        total_value += temp.second;
    }
    cout << total_value;
}