#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int,int>> dir;

int backup[10][10];
int map[10][10];

vector<pair<int,int>> virusebackup;
queue<pair<int,int>> viruses;

int n,m;

bool check(int y,int x){
    return (y>=0 && y<=n && x>=0 && x<=m);
}

void virusSpread(){
    pair<int,int> virus = viruses.front();
    viruses.pop();
    int virusY = virus.first;
    int virusX = virus.second;
    for(int i=0;i<4;i++){
        int y = virusY+dir[i].first;
        int x = virusX+dir[i].second;
        if(check(y,x) && map[y][x] == 0){
            map[y][x] = 2;
            viruses.push({y,x});
        }
    }
}

void reset(){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            map[i][j] = backup[i][j];
    
    while(!viruses.empty())
        viruses.pop();
    for(int i=0;i<virusebackup.size();i++)
        viruses.push(virusebackup[i]);
}

vector<pair<int,int>> decode(int a){
    vector<pair<int,int>> ans;
    for(int i=0;i<3;i++){
        int mr = a%m;
        a = a/m;
        int nr = a%n;
        a = a/n;
        ans.push_back({nr,mr});
    }
    return ans;
}

bool check_diff(vector<pair<int,int>>& test){
    return ( (test[0].first != test[1].first || test[0].second != test[1].second) && (test[0].first != test[2].first || test[0].second != test[2].second) && (test[1].first != test[2].first || test[1].second != test[2].second) );
}

bool is_Empty(vector<pair<int,int>>& test){
    bool judge = true;
    for(int i=0;i<test.size();i++){
        judge = judge && map[test[i].first][test[i].second] == 0;
    }
    return judge;
}
int size_calc(){
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] == 0)
                count ++;
        }
    }
    return count;
}
int throwDice(){
    int size_max = 0;
    for(int i=0;i<n*n*n*m*m*m;i++){
        reset();
        vector<pair<int,int>> wall = decode(i);
        if(!check_diff(wall) || !is_Empty(wall))
            continue;

        for(int j=0;j<3;j++)
        {
            map[wall[j].first][wall[j].second] = 1;
        }

        while(!viruses.empty()){
            virusSpread();
        }
        int size = size_calc();
        if(size_max < size)
            size_max = size;
    }
    return size_max;
}

int main(){
    dir.push_back({-1,0});
    dir.push_back({0,-1});
    dir.push_back({0,1});
    dir.push_back({1,0});
    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> backup[i][j];
            if(backup[i][j] == 2)
                virusebackup.push_back({i,j});
        }
    }

    int ans = throwDice();
    cout << ans;
}