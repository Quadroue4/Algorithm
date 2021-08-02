//1644.cpp

#include <iostream>
#include <vector>
using namespace std;

int eratos[4000001];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> prime;
    long long num = N;
    fill(eratos,eratos+(num+1),1);
    eratos[0] = 0;
    for(int i=2;i<=num;i++){
        long long count = i;
        if(eratos[i] == 0)
            continue;
        while(i*count<=num){
            eratos[i*count] = 0;
            count++;
        }
    }
    int count = 0;
    for(int i=2;i<=N;i++)
        if(eratos[i] == 1)
            prime.push_back(i);

    long long sum = 2;
    int start = 0;
    int end = 1;
    count = 0;
    while(end<=prime.size()){
        if(sum < N){
            sum += prime[end];
            end++;
        }
        else if(sum > N){
            sum -= prime[start];
            start++;
        }
        else{
            count++;
            sum += prime[end];
            end++;
        }
    }

    cout<<count;
}