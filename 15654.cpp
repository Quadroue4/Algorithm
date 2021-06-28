#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,M;
vector<vector<int>> ans;
bool isSelected[100];
void combination(vector<int> comb,int c){
    if(c!=0){
        comb.push_back(c);
    }
    if(comb.size() == M){
        ans.push_back(comb);
        return;
    }
    //int i = (c == 0 ? 1 : c);
    for(int i=1;i<=N;i++){
        //cout<<c<<" ";
        if(isSelected[i])
            continue;
        isSelected[i] = true;
        combination(comb,i);
        isSelected[i] = false;
    }
}

int main(){
    for(int i=0;i<100;i++)
        isSelected[i] = false;
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