//10942.cpp

#include <iostream>

using namespace std;

int dp[2001][2001];
int N;
int sequence[2001];

int is_palindrome(int start,int end){
    if(sequence[start] == sequence[end] && start+1 >= end )
        return 1;
    if(dp[start][end] != 0)
        return dp[start][end];
    
    //0이면 아직 설정도 안됐다는 이야기.
    if(sequence[start] == sequence[end])
        return dp[start][end] = is_palindrome(start+1,end-1);
    else
        return dp[start][end] = -1;
}

int main(){
    cin >> N;
    for(int i=1;i<=N;i++)
        cin >> sequence[i];
    int M;
    cin >> M;
    for(int i=0;i<M;i++){
        int S,E;
        scanf("%d %d",&S,&E);
        if(is_palindrome(S,E) > 0)
            cout<<"1\n";
        else
            cout<<"0\n";

    }
}