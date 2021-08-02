//1562.cpp
#include <iostream>

using namespace std;

int main(){
    int N;
    long long num = 1000000000;
    cin >> N;
    long long stairNumber[2][10][1024];

    for(int i=0;i<10;i++){
        for(int j=0;j<1024;j++){
            stairNumber[0][i][j] = 0;
        }
    }

    for(int i=1;i<10;i++){
        stairNumber[0][i][1<<i] = 1;
    }
    
    for(int k=0;k<N-1;k++){
        for(int i=0;i<10;i++){
            for(int j=0;j<1024;j++){
                stairNumber[(k+1)%2][i][j] = 0;
            }
        }
        for(int i=0;i<10;i++){
            for(int j=0;j<1024;j++){
                if(i-1>=0){ 
                    stairNumber[(k+1)%2][i-1][(1<<(i-1))|j] += stairNumber[k%2][i][j];
                    stairNumber[(k+1)%2][i-1][(1<<(i-1))|j] %= num;
                }
                if(i+1<=9){
                    stairNumber[(k+1)%2][i+1][(1<<(i+1))|j] += stairNumber[k%2][i][j];
                    stairNumber[(k+1)%2][i+1][(1<<(i+1))|j] %= num;
                }
            }
        }
    }
    long long sum = 0;
    for(int i=0;i<10;i++){
        sum += stairNumber[(N-1)%2][i][1023];
        sum %= num;
    }
    cout << sum%num;
}