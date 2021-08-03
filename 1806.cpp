//1806.cpp

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N,S;
    int arr[100000];
    cin >> N >> S;
    int start=0,end=1;
    long long sum = 0;
    for(int i=0;i<N;i++)
        cin >> arr[i];
    
    sum = arr[0];
    int mini = 0;
    while(start<end && end <= N){
        if(sum < S){
            sum += arr[end++];
        }
        else{
            if(mini == 0)
                mini = end-start;
            else{
                mini = min(mini,end-start);
            }
            sum -= arr[start++];
        }
    }

    cout<<mini;
}