#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int map[50][50];
vector<int> purifier;
vector<pair<int,int>> cycle_list;

vector<pair<int,int>> how_Many(int y,int x,int R,int C){
    vector<pair<int,int>> ans;
    if(y-1 >=0 && map[y-1][x] != -1)
        ans.push_back({y-1,x});
    if(x-1 >=0 && map[y][x-1] != -1)
        ans.push_back({y,x-1});
    if(y+1<R  && map[y+1][x] != -1)
        ans.push_back({y+1,x});
    if(x+1<C && map[y][x+1] != -1)
        ans.push_back({y,x+1});

    return ans;
}

void spreadSimulate(int R,int C){
    int tempMap[50][50];
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            tempMap[i][j] = 0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j] > 0){
                vector<pair<int,int>> dust_list = how_Many(i,j,R,C);
                tempMap[i][j] += map[i][j] - (map[i][j]/5)*dust_list.size();
                for(int k=0;k<dust_list.size();k++){
                    tempMap[dust_list[k].first][dust_list[k].second] += map[i][j]/5;
                }
            }
        }
    }

    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            map[i][j] = tempMap[i][j];
    
    map[purifier[0]][0] = -1;
    map[purifier[1]][0] = -1;
    
}

void purifySimulate(int R,int C){
    for(int i=purifier[0]-1;i>0;i--)
        map[i][0] = map[i-1][0];
    for(int i=0;i<C-1;i++)
        map[0][i] = map[0][i+1];
    for(int i=0;i<purifier[0];i++)
        map[i][C-1] = map[i+1][C-1];
    for(int i=C-1;i>1;i--)
        map[purifier[0]][i] = map[purifier[0]][i-1];

    map[purifier[0]][1] = 0;

    for(int i=purifier[1]+1;i<R-1;i++)
        map[i][0] = map[i+1][0];
    for(int i=0;i<C-1;i++)
        map[R-1][i] = map[R-1][i+1];
    for(int i=R-1;i>purifier[1];i--)
        map[i][C-1] = map[i-1][C-1];
    for(int i=C-1;i>1;i--)
        map[purifier[1]][i] = map[purifier[1]][i-1];

    map[purifier[1]][1] = 0;
}

int dust_Calc(int R,int C){
    int count = 0;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            count += map[i][j];
    return count+2; //공기 청정기가 도합 -2 이므로
}

void show(int R,int C){
    cout<<"\n";
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout<< map[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int simulate(int R,int C,int T){
    for(int i=0;i<T;i++){
        spreadSimulate(R,C);
        //cout<<"\n"<<"after spread"<<"\n";
        //show(R,C);
        purifySimulate(R,C);
        //cout<<"\n"<<"after purify"<<"\n";
        //show(R,C);
    }
    return dust_Calc(R,C);
}


int main(){
    int R,C,T;

    cin >> R >> C >> T;

    for(int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            cin >> map[i][j];
            if(map[i][j] == -1){
                purifier.push_back(i);
            }
        }
    }
    int ans;
    ans = simulate(R,C,T);

    cout<<ans;
}