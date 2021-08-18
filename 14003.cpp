//14003.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sequence[1000001];
int arr[1000001];
vector<int> candidate[1000001];

int find_idx(int x,int start,int end){
    if(start==end)
        return start;
    int mid = (start+end)/2;
    if(sequence[mid]>x){
        return find_idx(x,start,mid);
    }
    else if(sequence[mid]<x){
        return find_idx(x,mid+1,end);
    }
    else{
        return -1;
    }
}

int main(){
    int N;
    int a;
    cin >> N;
    int count = 0;
    vector<int> ans;
    for(int i=0;i<N;i++){
        scanf("%d",&a);
        int temp = find_idx(a,0,count);
        arr[i] = a;
        if(temp == -1)
            continue;
        candidate[temp].push_back(a);
        sequence[temp] = a;
        if(temp == count)
            count++;
    }
    cout<<count<<"\n";

    int big = candidate[count-1][0];
    ans.push_back(big);
    for(int i=count-2;i>=0;i--){
        for(int j=0;j<candidate[i].size();j++){
            if(candidate[i][j] < big){
                big = candidate[i][j];
                ans.push_back(big);
                break;
            }
        }
    }
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<" ";
}