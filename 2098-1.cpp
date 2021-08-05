//2098-1.cpp

/*
4
0 10 15 20
5 0 9 10
6 13 0 12
8 8 9 0

35
*/

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int city_to_city[20][20];
int dp[1<<16][16];
#define INF 987654321

int travel(int current,int visitNum){
    int bit = (1<<current);
    int ans = INF;
    visitNum = (visitNum | bit);
    if(dp[visitNum][current] != 0)
        return dp[visitNum][current];

    for(int i=1;i<N;i++){
        if(city_to_city[current][i] == 0)
            continue;
        if( (visitNum & (1<<i)) > 0)
            continue;
        int temp = city_to_city[current][i]+travel(i,visitNum);
        ans = min(ans,temp);
        dp[visitNum][current] = ans;
    }
    
    if(visitNum == ((1<<N)-1)){
        if(city_to_city[current][0] != 0){
            ans = city_to_city[current][0];
            dp[visitNum][current] = ans;
        }
    }
    
    visitNum = visitNum - bit;

    return ans;
}

int main(){
    cin >> N;
    for(int i=0;i<20;i++)
        for(int j=0;j<20;j++)
            city_to_city[i][j] = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> city_to_city[i][j];
        }
    }

    cout << travel(0,0);
}