//2618.cpp

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int W;
pair<int,int> cordinate[1002];
int dp[1002][1002];
int route[1000];

int distance(pair<int,int> a,pair<int,int> b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int do_dp(int a,int b){ // a <= b가 되도록
    int c = max(a,b);
    if(c == W+1)
        return 0;
    if(dp[a][b] != 0)
        return dp[a][b];
    
    int temp1 = distance(cordinate[a],cordinate[c+1])+do_dp(c+1,b);
    int temp2 = distance(cordinate[b],cordinate[c+1])+do_dp(a,c+1);

    return dp[a][b] = min(temp1,temp2);
}

void find_route(int a,int b){
    int c = max(a,b);
    if(c == W+1)
        return;
    int temp1 = distance(cordinate[a],cordinate[c+1])+do_dp(c+1,b);
    int temp2 = distance(cordinate[b],cordinate[c+1])+do_dp(a,c+1);

    if(temp1<temp2){
        cout<<"1\n";
        find_route(c+1,b);
    }
    else{
        cout<<"2\n";
        find_route(a,c+1);
    }
}

int main(){
    cin >> N;
    cin >> W;
    cordinate[0].first = 1;
    cordinate[0].second = 1;
    cordinate[1].first = N;
    cordinate[1].second = N;
    for(int i=2;i<=W+1;i++){
        cin >> cordinate[i].first >> cordinate[i].second;
    }
    do_dp(0,1);

    cout<<dp[0][1]<<"\n";

    find_route(0,1);
}