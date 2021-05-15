#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main(){
    int N;
    cin >> N;
    int arr[1000];

    queue<vector<int>> q; // value , idx , len
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    vector<int> arr1;
    int max_len=0;
    arr1.push_back(0);
    arr1.push_back(0);
    arr1.push_back(0);
    q.push(arr1);

    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        int value = temp[0];
        int idx = temp[1];
        int length = temp[2];
        max_len = max(max_len,length);
        int max_value = 99999999;

        for(int i=idx;i<N;i++){
            if(value < arr[i] && arr[i] < max_value){
                max_value = arr[i];
                vector<int> tp;
                tp.push_back(arr[i]);
                tp.push_back(i+1);
                tp.push_back(length+1);
                q.push(tp);
            }
        }
    }

    cout<<max_len;
}