//9292-1.cpp
//9252.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main(){
    string string1,string2;
    cin >> string1 >> string2;

    for(int i=0;i<string1.size();i++){
        for(int j=0;j<string2.size();j++){
            if(string1[i] == string2[j]){
                dp[i+1][j+1] = dp[i][j]+1;
            }
            else
                dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
        }
    }
/*
    for(int i=1;i<=string1.size();i++){
        for(int j=1;j<=string2.size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
*/
    vector<char> ans;
    int h=string1.size();
    int w=string2.size();

    while(h>0 && w>0){
        if(string1[h-1] == string2[w-1]){
            ans.push_back(string1[h-1]);
            h--;
            w--;
        }
        else{
            if(dp[h][w-1]>dp[h-1][w]){
                w--;
            }
            else{
                h--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<dp[string1.size()][string2.size()]<<"\n";

    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
}