#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int dp[1001];
int arr[1001];
int N;

int find_longest(int idx){
    if(dp[idx] != -1)
        return dp[idx];
    
    int value = arr[idx];
    int max_len = 1;
    for(int i=idx+1;i<N;i++){
        if(arr[i]>value){
            max_len = max(max_len,1+find_longest(i));
        }
    }
    dp[idx] = max_len;
    return max_len;
}

int main(){
    cin >> N;
    N++;
    for(int i=0;i<N;i++)
        dp[i] = -1;
    queue<vector<int>> q; // value , idx , len
    arr[0] = 0;
    for(int i=0;i<N-1;i++){
        cin >> arr[i+1];
    }

    int ans = find_longest(0);

    cout<<ans-1;
}