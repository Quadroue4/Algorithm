#include <iostream>
#include <vector>
#include <queue>

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
    for(int i=c+1;i<=N;i++){
        //cout<<c<<" ";
        combination(comb,i);
    }
}

int main(){
    cin >> N >> M;
    vector<int> temp;
    combination(temp,0);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}