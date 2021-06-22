#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp{
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second > b.second;
    }
};

int arr[100001];
priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> punc_list; //node 번호 , 비용

int main(){

    int N,K;
    cin >> N >> K;
    fill(arr,arr+100001,-1);

    int start = N;
    punc_list.push({start,0});
    while(!punc_list.empty()){
        auto temp = punc_list.top();
        int node = temp.first;
        int cost = temp.second;
        punc_list.pop();
        if(node < 0 || node > 100000 || arr[node] != -1)
            continue;
        arr[node] = cost;
        punc_list.push({node-1,cost+1});
        punc_list.push({node+1,cost+1});
        punc_list.push({node*2,cost});
        if(arr[K] != -1 && arr[start] > arr[K])
            break;
    }

    cout<<arr[K]<<endl;
}