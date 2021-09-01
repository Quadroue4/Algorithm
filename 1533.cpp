//1533.cpp

#include <iostream>

using namespace std;

int N,S,E,T;

long long **way_matrix1;
long long **way_matrix2;

void matrix_multiply(long long **a,long long **b){
    long long temp_matrix[50][50];
    for(int i=0;i<5*N;i++){
        for(int j=0;j<5*N;j++){
            long long sum = 0;
            for(int k=0;k<5*N;k++){
                sum += a[i][k]*b[k][j];
            }
            temp_matrix[i][j] = sum;
        }
    }
    for(int i=0;i<5*N;i++){
        for(int j=0;j<5*N;j++){
            way_matrix1[i][j] = temp_matrix[i][j]%1000003;
        }
    }
}

void do_multi(int t){
    if(t<2)
        return;
    else if(t==2){
        matrix_multiply(way_matrix2,way_matrix2);
        return;
    }

    else if(t%2 == 1){
        do_multi(t-1);
        matrix_multiply(way_matrix1,way_matrix2);
        return;
    }

    else{
        do_multi(t/2);
        matrix_multiply(way_matrix1,way_matrix1);
        return;
    }
}

int main(){
    cin >> N >> S >> E >> T;
    way_matrix1 = new long long*[5*N];
    way_matrix2 = new long long*[5*N];
    for(int i=0;i<5*N;i++){
        way_matrix1[i] = new long long[5*N];
        way_matrix2[i] = new long long[5*N];
    }
    for(int i=0;i<5*N;i++){
        for(int j=0;j<5*N;j++){
            way_matrix2[i][j] = 0;
        }
    }
    for(int i=0;i<N;i++){
        string str;
        cin >> str;
        for(int j=0;j<N;j++){
            int temp = str[j] - '0';
            if(temp>0)
                way_matrix2[5*i][5*j+temp-1] = 1;

            for(int k=1;k<temp;k++){
                way_matrix2[5*j+k][5*j+k-1] = 1;
            }
        }
    }
    do_multi(T);

    if(T>1)
        cout<<way_matrix1[5*(S-1)][5*(E-1)]%1000003;
    
    else
        cout<<way_matrix2[5*(S-1)][5*(E-1)]%1000003;
}