//1761-1.cpp
//1761.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int parent[40001];
int depth[40001];
int cost[40001];
int dp[40001][17]; //2^0 부터 2^16 까지 필요하므로. (1~40000)
int cost_dp[40001][17];
vector<pair<int,int>> informations[40001];
bool used[40001];

void initialize(){
    for(int i=2;i<=N;i++){
        dp[i][0] = parent[i];
        cost_dp[i][0] = cost[i];
    }

    int bit = 1;
    while(bit <= 16){
        for(int i=2;i<=N;i++){
            dp[i][bit] = dp[dp[i][bit-1]][bit-1];
            cost_dp[i][bit] = cost_dp[i][bit-1]+cost_dp[dp[i][bit-1]][bit-1];
        }
        bit++;
    }
}

int LCA(int a,int b){
    if(depth[a] > depth[b]){ // depth가 a <= b 가 되도록 만듬.
        int temp = a;
        a = b;
        b = temp; 
    }
    int i = 16;
    int sum = 0;
    while(depth[a] != depth[b]){
        while(depth[dp[b][i]] < depth[a]){
            i--;
        }
        sum += cost_dp[b][i];
        b = dp[b][i];
    }
    while(a != b){
        i=0;
        while(dp[a][i+1] != dp[b][i+1]){
            if(i<16)
                i++;
        }
        sum += cost_dp[a][i];
        sum += cost_dp[b][i];
        //cout<<cost_dp[a][i]<<" "<<cost_dp[b][i]<<"\n";
        a = dp[a][i];
        b = dp[b][i];
    }
    return sum;
}

void dfs(int a,int dep){
    for(int i=0;i<informations[a].size();i++){
        int temp = informations[a][i].first;
        int c = informations[a][i].second;
        if(temp != 1 && parent[temp] == 0){
            depth[temp] = dep+1;
            parent[temp] = a;
            cost[temp] = c;
            dfs(temp,dep+1);
        }
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N-1;i++){
        int s,e,c;
        scanf("%d %d %d",&s,&e,&c);
        informations[min(s,e)].push_back({max(s,e),c});
        informations[max(s,e)].push_back({min(s,e),c});
    }

    depth[1] = 1;
    dfs(1,1);//1을 루트로 설정.

    initialize(); //1을 넣으면 2^1 위의 조상을 찾고, 거기부터 ~~ 2^17승까지 찾도록 명령.

    scanf("%d",&M);
    for(int i=0;i<M;i++){
        int s,e;
        scanf("%d %d",&s,&e);
        cout<<LCA(s,e)<<"\n";
    }
}