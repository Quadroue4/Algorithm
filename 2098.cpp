//2098.cpp
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
int ans = 999999999;
bool visited[20];

void travel(int start,int current,int cost,int visitNum){
    if(visited[current])
        return;
    if(visitNum == N){
        int c = city_to_city[current][start];
        if(c != -1)
            ans = min(ans,cost+c);
        return;
    }
    visited[current] = true;
    int ans = 0;
    for(int i=1;i<=N;i++){
        if(city_to_city[current][i] == -1)
            continue;
        travel(start,i,cost+city_to_city[current][i],visitNum+1);
    }
    visited[current] = false;
}

int main(){
    cin >> N;
    for(int i=0;i<20;i++)
        for(int j=0;j<20;j++)
            city_to_city[i][j] = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int a;
            cin >> a;
            if(a !=  0)
                city_to_city[i][j] = a;
            else
                city_to_city[i][j] = -1;
        }
    }
    for(int i=0;i<20;i++)
        visited[i] = false;
    
    for(int i=1;i<=N;i++){
        travel(i,i,0,1);
    }
    cout << ans;
}