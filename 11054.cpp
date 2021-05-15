#include <iostream>
#include <cmath>

using namespace std;

int dpUp[1002];
int dpDown[1002];
int arr[1002];
int N;

int find_longest(int idx){
    int max_len = 0;
    for(int i=0;i<idx;i++){
        if(arr[idx] > arr[i])
            max_len = max(max_len,dpUp[i]);
    }
    dpUp[idx] = max_len+1;
    return dpUp[idx];
}
int find_smallest(int idx){
    int max_len = 0;
    for(int i=idx+1;i<N;i++){
        if(arr[idx] > arr[i])
            max_len = max(max_len,dpDown[i]);
    }
    dpDown[idx] = max_len+1;
    return dpDown[idx];
}

int main(){
    cin >> N;
    N += 2; // 맨앞에 0, 맨 뒤에 INT_MAX를 덧붙여 실행한다.
    arr[0] = 0;
    arr[N-1] = 1001;
    dpUp[0] = 1;
    dpDown[N-1] = 1;
    for(int i=1;i<N-1;i++){
        cin >> arr[i];
    }

    int ans = 0;
    for(int i=1;i<N-1;i++){
        find_longest(i);
        find_smallest(N-1-i);
    }

    for(int i=1;i<N-1;i++)
        ans = max(ans,dpUp[i]+dpDown[i]);
    cout<<ans-2;
}