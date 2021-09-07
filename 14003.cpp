//14003.cpp

#include <iostream>

using namespace std;

int sequence[1000001];
int idx[1000001];
int arr[1000001];
int parent[1000001];
int ans[1000001];

int find_idx(int x,int start,int end){
    if(start==end)
        return start;
    int mid = (start+end)/2;
    if(sequence[mid]>=x){
        return find_idx(x,start,mid);
    }
    else{
        return find_idx(x,mid+1,end);
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int N;
    int a;
    scanf("%d",&N);
    int count = 0;
    for(int i=1;i<=N;i++){
        scanf("%d",&a);
        int temp = find_idx(a,0,count);
        arr[i] = a;

        sequence[temp] = a;
        idx[temp] = i;
        if(temp>0)
            parent[i] = idx[temp-1];

        if(temp == count){
            count++;
        }

    }
    cout<<count<<"\n";
    int big = idx[count-1];
    int idxs = count-1;
    while(idxs>=0){
        ans[idxs] = arr[big];
        big = parent[big];
        idxs--;
    }
    for(int i=0;i<count;i++){
        cout<<ans[i]<<" ";
    }
}