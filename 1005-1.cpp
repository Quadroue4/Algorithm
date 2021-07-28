#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int build_time[1000];

void topological_sort(){

}

bool trynewTime(int a,int b){
    if(build_time[a] < b){
        build_time[a] = b;
        return true;
    }
    return false;
}

int main(){
    int N,K,T,a,b,w;
    cin >> T;
    for(int i=0;i<T;i++){
        int delay[1000];
        int build_follower[1000];
        int build_count[1000];
        queue<int> build_time_q;
        vector<int> building_connection[1000];
        fill(build_time,build_time+1000,0);
        fill(build_count,build_count+1000,0);
        fill(build_follower,build_follower+1000,0);

        cin >> N >> K;

        for(int j=0;j<N;j++){
            cin >> delay[j];
        }

        for(int j=0;j<K;j++){
            cin >> a >> b;
            building_connection[a-1].push_back(b-1);
            build_follower[b-1]++;
        }
        cin >> w;
        for(int j=0;j<N;j++)
            if(build_follower[j] == 0){
                build_time_q.push(j);
                build_time[j] = delay[j];
            }
        
        while(!build_time_q.empty()){
            int temp = build_time_q.front();
            build_time_q.pop();
                for(int j=0;j<building_connection[temp].size();j++){
                    int idx = building_connection[temp][j];
                    build_follower[idx]--;
                    trynewTime(idx,build_time[temp]+delay[idx]);
                    if(build_follower[idx] == 0)
                        build_time_q.push(idx);
                }
            }
        cout<<build_time[w-1]<<" ";
    }
}