#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,M;
vector<vector<int>> ans;

bool isUsed[100];

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

    for(int i = 1;i<=N;i++){
        if(isUsed[i])
            continue;
        isUsed[i] = true;
        combination(comb,i);
        isUsed[i] = false;
    }
}

int main(){
    for(int i=0;i<100;i++)
        isUsed[i] = false;
    cin >> N >> M;

    vector<int> temp;
    int arr[100];

    combination(temp,0);

    for(int i=0;i<N;i++)
        cin>>arr[i];
    
    sort(arr,arr+N);

    vector<vector<int>> ans2;
    for(int i=0;i<ans.size();i++){
        vector<int> temp;
        for(int j=0;j<ans[i].size();j++){
            temp.push_back(arr[ans[i][j]-1]);
        }
        ans2.push_back(temp);
    }

    sort(ans2.begin(),ans2.end());

    vector<int> temp1;
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