//11505.cpp
#include <iostream>
#include <cmath>

using namespace std;
#define divider 1000000007;

int N,M,K;
long long segment_tree[4000000];

void change_idx(int start,int end,int query,int Node,int value){
    if(start == query && end == query){
        int temp = segment_tree[Node];
        segment_tree[Node] = value;
        return;
    }
    int mid = (start+end)/2;

    if(mid < query){
        change_idx(mid+1,end,query,Node*2+1,value);
    }
    else if(query <= mid){
        change_idx(start,mid,query,Node*2,value);
    }

    long long a = segment_tree[Node*2];
    long long b = segment_tree[Node*2+1];
    segment_tree[Node] = a*b%divider;
}

int init_multiple(int start,int end,int Node){
    if(start == end){
        return segment_tree[Node];
    }
    int mid = (start+end)/2;
    long long a = init_multiple(start,mid,Node*2);
    long long b = init_multiple(mid+1,end,Node*2+1);
    return segment_tree[Node] = a*b%divider;
}

int calc_multiple(int start,int end,int query_start,int query_end,int Node){
    if(start == query_start && end == query_end){
        return segment_tree[Node];
    }

    int mid = (start+end)/2;

    if(mid < query_start){
        return calc_multiple(mid+1,end,query_start,query_end,Node*2+1);
    }

    else if(query_end <= mid){
        return calc_multiple(start,mid,query_start,query_end,Node*2);
    }

    long long a = calc_multiple(start,mid,query_start,mid,Node*2);
    long long b = calc_multiple(mid+1,end,mid+1,query_end,Node*2+1);

    return a*b%divider;
}

void see(){
    cout<<"\n";
    for(int i=1;i<=N;i++){
        cout<<segment_tree[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    cin >> N >> M >> K;
    for(int i=1;i<=3000000;i++)
        segment_tree[i] = 1;
    int a,b,c;
    for(int i=1;i<=N;i++){
        scanf("%d",&a);
        change_idx(1,N,i,1,a);
    }

    init_multiple(1,N,1);

    for(int i=0;i<M+K;i++){
        scanf("%d %d %d",&a,&b,&c);
        if(a == 1){
            change_idx(1,N,b,1,c);
        }
        else{
            cout<<calc_multiple(1,N,b,c,1)<<"\n";
        }
    }
}