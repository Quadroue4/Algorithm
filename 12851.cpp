#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[100001];
int way[100001];
queue<int> punc_list;
void move_from(int a){
    if(a-1 >=0 && (arr[a-1] == -1 || arr[a-1] == arr[a]+1)){
        arr[a-1] = arr[a]+1;
        way[a-1]++;
        punc_list.push(a-1);
    }
    if(a+1 <=100000 && (arr[a+1] == -1 || arr[a+1] == arr[a]+1)){
        arr[a+1] = arr[a]+1;
        way[a+1]++;
        punc_list.push(a+1);
    }
    if(2*a <= 100000 && (arr[2*a] == -1 || arr[2*a] == arr[a]+1)){
        arr[2*a] = arr[a]+1;
        way[2*a]++;
        punc_list.push(2*a);
    }
}


int main(){

    int N,K;
    cin >> N >> K;
    fill(arr,arr+100001,-1);
    fill(way,way+100001,0);

    arr[N] = 0;
    way[N] = 1;
    int start = N;
    punc_list.push(start);
    while(true && !punc_list.empty()){
        start = punc_list.front();
        punc_list.pop();
        move_from(start);
        if(arr[K] != -1 && arr[start] > arr[K])
            break;
    }

    cout<<arr[K]<<endl;
    cout<<way[K];

}