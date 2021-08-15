//11049.cpp

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int dp[501][501];
int sequence[501];

int find_dp(int start,int end){
    if(dp[start][end] != 0)
        return dp[start][end];

    if(start == end)
        return 0;
    if(start+1 == end){
        return dp[start][end] = sequence[start]*sequence[start+1]*sequence[start+2];
    }

    if(start+2 == end){
        return dp[start][end] = min(sequence[start]*sequence[start+1]*sequence[start+2]+sequence[start]*sequence[start+2]*sequence[start+3],
                                    sequence[start+1]*sequence[start+2]*sequence[start+3]+sequence[start]*sequence[start+1]*sequence[start+3]);
    }
    int sum = INT_MAX;
    for(int i=start;i<end;i++){
        int temp = sequence[start]*sequence[i+1]*sequence[end+1];
        temp += find_dp(start,i);
        temp += find_dp(i+1,end);
        sum = min(sum,temp);
    }
    return dp[start][end] = sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N;

    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        sequence[i] = a;
        sequence[i+1] = b;
    }
    find_dp(0,N-1);
    cout<<dp[0][N-1];
}