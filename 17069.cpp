#include <iostream>
#include <queue>
#include <vector>

using namespace std;

enum State{
    HORIZONTAL,
    DIAGONAL,
    VERTICAL,
};

int arr[40][40];
long dp[40][40][3];
int N;
bool checker(pair<int,int> point,State s,int N){
    if(point.first > N || point.second > N)
        return false;
    if(s == DIAGONAL){
        return arr[point.first][point.second-1] == 0 && arr[point.first][point.second] == 0 && arr[point.first-1][point.second] == 0;
    }
    else
        return arr[point.first][point.second] == 0;
}

__int64_t pipe_move(pair<int,int> a,State s){

    if(dp[a.first][a.second][s] != -1)
        return dp[a.first][a.second][s];

    if(!checker(a,s,N)){
        dp[a.first][a.second][s] = 0;
        return 0;
    }
    __int64_t sum = 0;
    if(a.first == N && a.second == N)
        return 1;
    if(s == HORIZONTAL){
        sum += pipe_move({a.first+1,a.second+1},DIAGONAL);
        sum += pipe_move({a.first,a.second+1},HORIZONTAL);
        dp[a.first][a.second][s] = sum;
    }
    else if(s == VERTICAL){
        sum += pipe_move({a.first+1,a.second+1},DIAGONAL);
        sum += pipe_move({a.first+1,a.second},VERTICAL);
        dp[a.first][a.second][s] = sum;
    }
    else{
        __int64_t x,y,z;
        x = pipe_move({a.first+1,a.second+1},DIAGONAL);
        y = pipe_move({a.first,a.second+1},HORIZONTAL);
        z = pipe_move({a.first+1,a.second},VERTICAL);
        dp[a.first][a.second][DIAGONAL] = x+y+z;
        dp[a.first][a.second][HORIZONTAL] = x+y;
        dp[a.first][a.second][VERTICAL] = x+z;
        return x+y+z;
    }
    //cout << sum<<endl;
    return sum;
}

int main(){
    cin >> N;
    for(int i=0;i<40;i++){
        for(int j=0;j<40;j++){
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
            dp[i][j][2] = -1;
        }
    }
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin >> arr[i][j];
    
    __int64_t ans = pipe_move({1,2},HORIZONTAL);

    cout<<ans;

}