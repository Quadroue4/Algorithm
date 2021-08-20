//1006.cpp

#include <iostream>
#include <algorithm>

using namespace std;

int map[2][10005];
int dp[2][10005];
bool used[2][10005];
int N,W;
int ans;

void clear_dp(){
    for(int i=0;i<2;i++)
        for(int j=0;j<N;j++)
            dp[i][j] = 0;
}

void see(){
    for(int i=0;i<2;i++){
        for(int j=0;j<N;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool can_horizontal_invade(int y,int x){
    return (map[y][x]+map[y][(x+1)%N]<=W) && (!used[y][x] && !used[y][(x+1)%N]);
}

bool can_vertical_invade(int y,int x){
    return (map[y][x]+map[(y+1)%2][x]<=W) && (!used[y][x] && !used[(y+1)%2][x]);
}

void do_horizontal_invade(int y,int x){
    used[y][x] = true;
    used[y][(x+1)%N] = true;
}

void do_vertical_invade(int y,int x){
    used[y][x] = true;
    used[(y+1)%2][x] = true;
}

void undo_horizontal_invade(int y,int x){
    used[y][x] = false;
    used[y][(x+1)%N] = false;
}

void undo_vertical_invade(int y,int x){
    used[y][x] = false;
    used[(y+1)%2][x] = false;
}

void do_point_invade(int y,int x){
    used[y][x] = true;
}

void undo_point_invade(int y,int x){
    used[y][x] = false;
}

int solve_col(int y,int x){
    int candidate = 2099999999;

    if(x==N){
        return 0;
    }

    if(used[y][x] == true){
        return solve_col( (y+1)%2,x+(y+1)/2);
    }
    if(used[0][x] == false && used[1][x] == false && dp[0][x] != 0){
        return dp[0][x];
    }
    else if(used[0][x] == true && used[0][x+1] == false && used[1][x] == false && dp[1][x] != 0){
        return dp[1][x];
    }

    else if(used[0][x] == false && used[1][x] == true){
        if(can_horizontal_invade(0,x)){
            do_horizontal_invade(0,x);
            candidate = min(candidate,1+solve_col(1,x+1));
            undo_horizontal_invade(0,x);
        }
        else{
            do_point_invade(0,x);
            candidate = min(candidate,1+solve_col(0,x+1));
            undo_point_invade(0,x);
        }
        return candidate;
    }

    if(can_vertical_invade(y,x)){
        do_vertical_invade(y,x);
        candidate = min(candidate,1+solve_col( 0,x+1 ));
        undo_vertical_invade(y,x);
    }

    if(can_horizontal_invade(y,x)){
        do_horizontal_invade(y,x);
        candidate = min(candidate,1+solve_col( (y+1)%2,x+(y+1)/2 ) );
        undo_horizontal_invade(y,x);
    }
    
    do_point_invade(y,x);
    candidate = min(candidate,1+solve_col( (y+1)%2,x+(y+1)/2 ));
    undo_point_invade(y,x);
    if(y==0)
        return dp[y][x] = candidate;
    else if(y==1 && used[0][x+1] == false)
        return dp[y][x] = candidate;
    
    else
        return candidate;
}

void Solve(){
    cin >> N >> W;
    for(int i=0;i<N;i++){
        cin >> map[0][i];
    }
    for(int i=0;i<N;i++){
        cin >> map[1][i];
    }

    ans = 2000000000;

    if(can_horizontal_invade(0,N-1) && can_horizontal_invade(1,N-1)){
        clear_dp();
        do_horizontal_invade(0,N-1);
        do_horizontal_invade(1,N-1);
        ans = min(ans,2+solve_col(1,0));
        undo_horizontal_invade(0,N-1);
        undo_horizontal_invade(1,N-1);
    }

    if(can_horizontal_invade(0,N-1)){
        clear_dp();
        do_horizontal_invade(0,N-1);
        ans = min(ans,1+solve_col(1,0));
        undo_horizontal_invade(0,N-1);
    }

    if(can_horizontal_invade(1,N-1)){
        clear_dp();
        do_horizontal_invade(1,N-1);
        ans = min(ans,1+solve_col(0,0));
        undo_horizontal_invade(1,N-1);
    }

    clear_dp();

    ans = min(ans,solve_col(0,0));

    cout<<ans<<"\n";
}


int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        Solve();
    }
}