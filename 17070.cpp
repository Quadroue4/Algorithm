#include <iostream>
#include <queue>
#include <vector>

using namespace std;

enum State{
    HORIZONTAL,
    DIAGONAL,
    VERTICAL,
};

int arr[20][20];

bool checker(pair<int,int> point,State s,int N){
    if(point.first > N || point.second > N)
        return false;
    if(s == DIAGONAL){
        return (arr[point.first][point.second-1] == 0 && arr[point.first][point.second]==0 && arr[point.first-1][point.second]==0);
    }
    else
        return arr[point.first][point.second]==0;
}

int main(){
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin >> arr[i][j];
    queue<pair<pair<int,int>,State>> q;
    q.push({{1,2},HORIZONTAL});
    int count = 0;
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        auto point = temp.first;
        State s = temp.second;
        if(!checker(point,s,N))
            continue;
        if(point.first == N && point.second == N){
            count++;
            continue;
        }
        if(s == HORIZONTAL){
            q.push({{point.first,point.second+1},HORIZONTAL});
            q.push({{point.first+1,point.second+1},DIAGONAL});
        }
        else if(s == DIAGONAL){
            q.push({{point.first,point.second+1},HORIZONTAL});
            q.push({{point.first+1,point.second+1},DIAGONAL});
            q.push({{point.first+1,point.second},VERTICAL});
        }
        else{
            q.push({{point.first+1,point.second},VERTICAL});
            q.push({{point.first+1,point.second+1},DIAGONAL});
        }
    }
    cout << count;
}