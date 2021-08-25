//1014.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[10][10]; //0 : 빈자리 1 : 막힌자리 2 : 앉은자리
int dp[11][1024];
int N,M;

bool is_student(int y,int x){
    if(y>0 && x>=0 && y<=N && x<M){
        if(board[y][x] == 2)
            return true;
    }
    return false;
}

bool can_put(int y,int x){
    bool judge = false;
    judge = judge || (board[y][x] != 0);
    judge = judge || is_student(y-1,x-1);
    judge = judge || is_student(y-1,x+1);
    judge = judge || is_student(y,x-1);
    judge = judge || is_student(y,x+1);

    return !judge;
}

void put_student(int y,int x){
    board[y][x] = 2;
}

void erase_student(int y,int x){
    if(board[y][x] == 2)
        board[y][x] = 0;
}

int make_int(int y){
    int count = 0;
    for(int i=0;i<M;i++){
        count *= 2;
        if(board[y][i] == 2)
            count += 1;
    }
    return count;
}

int do_dp(int y,int x){ //y,x에 student가 있따는 가정하에 진행
    if(y>N)
        return 0;
    if(dp[y][make_int(y-1)] > 0)
        return dp[y][make_int(y-1)];
    
    int ans = do_dp(y+1,-1);

    for(int i=x+1;i<M;i++){
        if(can_put(y,i)){
            put_student(y,i);
            ans = max(ans,do_dp(y,i)+1);
            erase_student(y,i);
        }
    }

    if(x == -1)
        return dp[y][make_int(y-1)] = ans;
    else
        return ans;
}

void clear_dp(){
    for(int i=0;i<=N;i++){
        for(int j=0;j<1024;j++)
            dp[i][j] = 0;
        for(int j=0;j<M;j++){
            board[i][j] = 0;
        }
    }
}

void Solve(){
    cin >> N >> M;
    clear_dp();
    for(int i=1;i<=N;i++){
        string a;
        cin >> a;
        for(int j=0;j<M;j++){
            if(a[j] == 'x')
                board[i][j] = 1;
            else
                board[i][j] = 0;
        }
    }
    do_dp(1,-1);
    cout<<dp[1][0]<<"\n";
}

int main(){
    int C;
    cin >> C;
    for(int i=0;i<C;i++){
        Solve();
    }
}