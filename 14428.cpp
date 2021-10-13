//14428.cpp

#include <iostream>
#include <vector>

using namespace std;

int N,M;
pair<int,int> segment_tree[400000];

void change_min_idx(int start,int end,int query_idx,int query_value,int Node){
    if(start == query_idx && end == query_idx){
        segment_tree[Node] = {query_idx,query_value};
        return;
    }

    int mid = (start+end)/2;

    if(query_idx <= mid){
        change_min_idx(start,mid,query_idx,query_value,Node*2);
    }
    else if(mid < query_idx){
        change_min_idx(mid+1,end,query_idx,query_value,Node*2+1);
    }

    pair<int,int> a = segment_tree[Node*2];
    pair<int,int> b = segment_tree[Node*2+1];

    segment_tree[Node] = a.second <= b.second ? a : b;
}

pair<int,int> calc_min_idx(int start,int end,int query_start,int query_end,int Node){
    if(start == query_start && end == query_end){
        return segment_tree[Node];
    }

    int mid = (start+end)/2;

    if(query_end <= mid){
        return calc_min_idx(start,mid,query_start,query_end,Node*2);
    }

    else if(mid < query_start){
        return calc_min_idx(mid+1,end,query_start,query_end,Node*2+1);
    }

    pair<int,int> a = calc_min_idx(start,mid,query_start,mid,Node*2);
    pair<int,int> b = calc_min_idx(mid+1,end,mid+1,query_end,Node*2+1);

    return a.second <= b.second ? a : b;
}

int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        int v;
        scanf("%d",&v);
        change_min_idx(1,N,i,v,1);
    }

    scanf("%d",&M);
    for(int i=0;i<M;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a==1){
            change_min_idx(1,N,b,c,1);
        }
        else{
            cout<<calc_min_idx(1,N,b,c,1).first<<"\n";
        }
    }
}