//1019.cpp

#include <iostream>

using namespace std;

long long dp[10];
long long count_n[10];
void count_num(int n){
    for(int i=0;i<10;i++)
        count_n[i] = 0;
    while(n>0){
        count_n[n%10]++;
        n /= 10;
    }
    return;
}

void do_dp(int n){
    if(n<10){
        for(int i=1;i<=n;i++){
            dp[i] = 1;
        }
        return;
    }
    do_dp(n/10);
    long long temp_dp[10];
    for(int i=0;i<10;i++)
        temp_dp[i] = n/10;

    temp_dp[0]--;
    
    for(int i=0;i<=n%10;i++){
        count_num( (n/10)*10+i );
        for(int j=0;j<10;j++){
            temp_dp[j] += count_n[j];
        }
    }

    count_num(n/10);
    for(int i=0;i<10;i++)
        dp[i] -= count_n[i];

    for(int i=0;i<10;i++){
        temp_dp[i] += dp[i]*10;
    }

    for(int i=0;i<10;i++)
        dp[i] = temp_dp[i];
}

int main(){
    int N;
    cin >> N;

    do_dp(N);

    for(int i=0;i<10;i++){
        cout<<dp[i]<<" ";
    }
}