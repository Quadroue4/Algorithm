//2342.cpp

#include <iostream>
#include <algorithm>

using namespace std;

int dp[11][100001];
int sequence[100001];
pair<int,int> mystate;

int state_to_int(pair<int,int> state){
    int left = state.first;
    int right = state.second;
    if(left > right){
        int temp = right;
        right = left;
        left = temp;
    }
    if(left==0 && right == 0)
        return 0;
    if(left == 0 && right == 1)
        return 1;
    if(left == 0 && right == 2)
        return 2;
    if(left == 0 && right == 3)
        return 3;
    if(left == 0 && right ==4 )
        return 4;
    if(left == 1 && right == 2)
        return 5;
    if(left == 1 && right == 3)
        return 6;
    if(left == 1 && right == 4)
        return 7;
    if(left == 2 && right == 3)
        return 8;
    if(left == 2 && right == 4)
        return 9;
    if(left == 3 && right == 4)
        return 10;
    return 0;
}

int cost_calculate(int from,int to){
    if(from == to)
        return 1;
    if(from == 0)
        return 2;
    if( (from == 1 && (to == 2 || to == 4) ) || (from == 2 && (to == 1 || to == 3) ) || (from == 3 && (to == 2 || to == 4) ) || (from == 4 && (to == 1 || to == 3) ) )
        return 3;
    if( (from == 2 && to == 4) || (from == 4 && to == 2) || (from == 1 && to == 3) || (from == 3 && to == 1))
        return 4;
    return 0;
}

int dps(int progress){
    int s = state_to_int(mystate);

    if(sequence[progress] == 0)
        return 0;
    if(dp[s][progress] != 0)
        return dp[s][progress];

    int next = sequence[progress];
    int mini = 999999999;
    int left = mystate.first;
    int right = mystate.second;
    int left_cost = cost_calculate(left,next);
    int right_cost = cost_calculate(right,next);
    mystate = {next,right};
    mini = min(mini,left_cost+dps(progress+1));
    mystate = {left,next};
    mini = min(mini,right_cost+dps(progress+1));

    mystate = {left,right};

    dp[s][progress] = mini;

    return mini;
}

int main(){
    for(int i=0;true;i++){
        int a;
        cin >> a;
        sequence[i] = a;
        if(a==0)
            break;
    }

    mystate = {0,0};
    cout<< dps(0);
}