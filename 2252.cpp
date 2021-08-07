//2252.cpp

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> height[32001];
int follower[32001];
queue<int> orderedheight;
int main(){
    int N,M;
    vector<int> ans;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        height[a].push_back(b);
        follower[b]++;
    }

    for(int i=1;i<=N;i++){
        if(follower[i] == 0){
            orderedheight.push(i);
        }
    }

    while(!orderedheight.empty()){
        int a = orderedheight.front();
        ans.push_back(a);
        orderedheight.pop();
        for(int i=0;i<height[a].size();i++){
            int b = height[a][i];
            follower[b]--;
            if(follower[b] == 0){
                orderedheight.push(b);
            }
        }
    }

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}