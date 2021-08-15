//12850.cpp

#include <iostream>
#include <vector>

using namespace std;

long long building[8];
long long save[8][8]; //i번째 빌딩에만 1이 존재할때 n번 굴렸을때의 상태표
long long temp[8];
vector<long long> connection[8];

void walk(){
    for(int i=0;i<8;i++)
        temp[i] = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<connection[i].size();j++){
            temp[connection[i][j]] += building[i];
            //cout<<"FROM "<<i<<" TO "<<connection[i][j]<<" "<<building[i]<<"\n";
        }
    }
    for(int i=0;i<8;i++){
        if(temp[i] < 1000000007)
            building[i] = temp[i];//%m00007;
        else
            building[i] = temp[i]%1000000007;
    }
}

void fast_walk(){
    for(int i=0;i<8;i++)
        temp[i] = 0;
    
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            temp[j] += building[i]*save[i][j];
            temp[j] %= 1000000007;
        }
    }
    for(int i=0;i<8;i++)
        building[i] = temp[i];
}

int main(){
    int n;
    cin >> n;
    connection[0].push_back(1);
    connection[0].push_back(2);
    connection[1].push_back(0);
    connection[1].push_back(2);
    connection[1].push_back(3);
    connection[2].push_back(0);
    connection[2].push_back(1);
    connection[2].push_back(3);
    connection[2].push_back(4);
    connection[3].push_back(1);
    connection[3].push_back(2);
    connection[3].push_back(4);
    connection[3].push_back(5);
    connection[4].push_back(2);
    connection[4].push_back(3);
    connection[4].push_back(5);
    connection[4].push_back(7);
    connection[5].push_back(3);
    connection[5].push_back(4);
    connection[5].push_back(6);
    connection[6].push_back(5);
    connection[6].push_back(7);
    connection[7].push_back(4);
    connection[7].push_back(6);

    int m = 10000;
    for(int j=0;j<8;j++){
        for(int i=0;i<8;i++)
            building[i] = 0;
        building[j] = 1;
        for(int i=0;i<m;i++)
            walk();
        for(int i=0;i<8;i++)
            save[j][i] = building[i];
    }

    for(int i=0;i<8;i++)
        building[i] = 0;
    building[0] = 1;

    for(int i=0;i<n/m;i++)
        fast_walk();
    for(int i=0;i<n%m;i++){
        walk();
    }
    cout<<building[0];
}