#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int dp[1001];
int arr[1001];
int N;

int find_longest(int idx){
    int max_len = 0;
    for(int i=0;i<idx;i++){
        if(arr[idx] > arr[i])
            max_len = max(max_len,dp[i]);
    }
    dp[idx] = max_len+1;
    return dp[idx];
}

int main(){
    cin >> N;
    N++;
    for(int i=0;i<N;i++)
        dp[i] = -1;
    arr[0] = 0;
    dp[0] = 1;
    for(int i=1;i<N;i++){
        cin >> arr[i];
    }

    int ans = 0;
    for(int i=1;i<N;i++){
        ans = max(ans,find_longest(i));
    }
    cout<<ans-1;
}