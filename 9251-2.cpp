#include <iostream>
#include <string>

using namespace std;
string a,b;
int dp[1001][1001];
int main(){
    cin>>a>>b;
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            dp[i][j] = a[i-1]==b[j-1] ? 1+dp[i-1][j-1] : max(dp[i-1][j],dp[i][j-1]);
        }
    }

    cout<<dp[a.size()][b.size()];
}