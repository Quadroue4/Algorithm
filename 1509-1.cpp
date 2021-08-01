//1509-1.cpp
#include <iostream>
#include <algorithm>

using namespace std;

int is_palindrome[2501][2501];
int dp[2501];

int main(){
    string input;
    cin >> input;

    int str_size = input.size();

    for(int i=1;i<=str_size;i++)
        is_palindrome[i][i] = 1;

    dp[0] = 0;
    for(int i=1;i<=str_size;i++){
        dp[i] = dp[i-1] + 1;
        for(int j=i-1;j>0;j--){
            if(input[i-1]==input[j-1] && (j+1==i || is_palindrome[j+1][i-1]) ){
                is_palindrome[j][i] = 1;
                dp[i] = min(dp[i],dp[j-1]+1);
            }
        }
    }
    cout<<dp[str_size];
}