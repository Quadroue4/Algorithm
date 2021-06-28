#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,M;
vector<vector<int>> ans;

void combination(vector<int> comb,int c){
    if(c!=0)
        comb.push_back(c);
    if(comb.size() == M){
        ans.push_back(comb);
        return;
    }
    int i = (c == 0 ? 1 : c);
    for(;i<=N;i++){
        combination(comb,i);
    }
}

int main(){
    cin >> N >> M;
    vector<int> temp;
    int arr[100];
    combination(temp,0);

    for(int i=0;i<N;i++)
        cin>>arr[i];
    
    sort(arr,arr+N);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<arr[ans[i][j]-1]<<" ";
        }
        cout<<"\n";
    }
}