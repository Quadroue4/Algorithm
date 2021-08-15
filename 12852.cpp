//12852.cpp

#include <iostream>

using namespace std;

int dp[1000001];
int follower[1000001];

int main(){
    int n;
    cin >> n;

    follower[1] = 0;

    for(int i=0;i<1000001;i++)
        dp[i] = 999999999;
    dp[1] = 0;
    for(int i=1;i<1000000;i++){
        if(dp[i]+1 < dp[i+1]){
            follower[i+1] = i;
            dp[i+1] = min(dp[i+1],dp[i]+1);
        }
        if(2*i <=1000000 && dp[i]+1 < dp[2*i]){
            dp[2*i] = dp[i]+1;
            follower[2*i] = i;
        }
        if(3*i <= 1000000 && dp[i]+1 < dp[3*i]){
            dp[3*i] = dp[i]+1;
            follower[3*i] = i;
        }
    }

    cout<<dp[n]<<"\n";
    while(n>0){
        cout<<n<<" ";
        n = follower[n];
    }
    
}