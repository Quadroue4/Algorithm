#include <iostream>

using namespace std;
int main(){
    int TestCase;
    cin >> TestCase;
    for(int i=0;i<TestCase;i++){
        int arr[2][100000];
        int dp[2][100000];
        int n;
        cin >> n;
        for(int j=0;j<n;j++)
            cin >> arr[0][j];
        for(int j=0;j<n;j++)
            cin >> arr[1][j];
        if(n<2){
            cout<<max(arr[0][0],arr[1][0]);
            return 0;
        }
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = dp[1][0] + arr[0][1];
        dp[1][1] = dp[0][0] + arr[1][1];
        for(int k=2;k<n;k++){
            for(int j=0;j<2;j++){
                dp[j][k] = arr[j][k] + max(dp[(j+1)%2][k-1],dp[(j+1)%2][k-2]);
            }
        }
        cout<<max(dp[1][n-1],dp[0][n-1])<<"\n";
    }

}