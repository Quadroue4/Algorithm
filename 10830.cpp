#include <iostream>
#include <vector>

using namespace std;

int** dp[40];

void mat_multi(int **ans,int **a,int **b,int n){
    int ** temp;
    temp = new int*[n];
    for(int i=0;i<n;i++)
        temp[i] = new int[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int sum = 0;
            for(int k=0;k<n;k++){
                sum += (a[i][k]*b[k][j])%1000;
            }
            temp[i][j] = sum%1000;
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans[i][j] = temp[i][j];
}

int main(){
    int N;
    long long B;
    cin >> N >> B;
    long long maxb = 40;
    for(int i=0;i<maxb;i++){
        dp[i] = new int*[N];
        for(int j=0;j<N;j++)
            dp[i][j] = new int[N];
    }
    int**a = new int*[N];
    for(int i=0;i<N;i++){
        a[i] = new int[N];
        for(int j=0;j<N;j++){
            if(i == j)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>dp[1][i][j];
    
    int depth = 0;

    for(long long i=1;i<= ((B & (1<<maxb)-1));i*=2){
        depth ++;
        if(((B>>(depth-1)) & 1) == 1){
            mat_multi(a,a,dp[depth],N);
        }
        mat_multi(dp[depth+1],dp[depth],dp[depth],N);
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}