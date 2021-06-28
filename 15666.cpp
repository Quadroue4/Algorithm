//15666.cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,M;
vector<vector<int>> ans;

bool isSame(vector<int> a,vector<int> b){
    for(int i=0;i<a.size();i++)
        if(a[i] != b[i])
            return false;
    return true;
}

void combination(vector<int> comb,int c){
    if(c!=0)
        comb.push_back(c);
    if(comb.size() == M){
        ans.push_back(comb);
        return;
    }

    int i = (c==0 ? 1 : c);
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
    vector<int> temp1;
    vector<vector<int>> ans2;

    for(int i=0;i<ans.size();i++){
        vector<int> temp;
        for(int j=0;j<ans[i].size();j++){
            temp.push_back(arr[ans[i][j]-1]);
        }
        ans2.push_back(temp);
    }

    sort(ans2.begin(),ans2.end());

    for(int i=0;i<M;i++)
        temp1.push_back(-1);
    for(int i=0;i<ans2.size();i++){
        vector<int> temp2;
        for(int j=0;j<ans2[i].size();j++){
            temp2.push_back(ans2[i][j]);
        }
        if(isSame(temp1,temp2))
            continue;
        temp1 = temp2;
        for(int j=0;j<ans2[i].size();j++){
            cout<<ans2[i][j]<<" ";
        }
        cout<<"\n";
    }
}