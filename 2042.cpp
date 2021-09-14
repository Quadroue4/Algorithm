//2042.cpp

#include <iostream>

using namespace std;

long long N,M,K;
long long sequence[1000000];
long long segment_tree[20000001];
int seg_idx[1000000];

long long init_seg(int start,int end,int Node){
    if(start == end){
        seg_idx[start] = Node;
        return segment_tree[Node] = sequence[start];
    }

    return segment_tree[Node] = init_seg(start,(start+end)/2,Node*2) + init_seg((start+end)/2+1,end,Node*2+1);
}

void see(){
    for(int i=0;i<N;i++){
        int node_idx = seg_idx[i];
        cout<<segment_tree[node_idx]<<" ";
    }
    cout<<"\n";
}

void update(long long idx,long long value){
    int node_idx = seg_idx[idx-1];
    segment_tree[node_idx] = value;
    node_idx /= 2;
    while(node_idx>0){
        segment_tree[node_idx] = segment_tree[node_idx*2] + segment_tree[node_idx*2+1];
        node_idx /= 2;
    }
}

long long calc(long long start,long long end,long long left,long long right,long long Node){
    //cout<<start<<" "<<end<<" "<<left<<" "<<right<<" "<<segment_tree[Node]<<"\n";
    if(end < start)
        return 0;
    if(start == left && end == right){
        return segment_tree[Node];
    }
    long long mid = (left+right)/2;
    if(end <= mid)
        return calc(start,end,left,mid,2*Node);
    if(mid < start)
        return calc(start,end,mid+1,right,2*Node+1);

    return calc(start,mid,left,mid,Node*2) + calc(mid+1,end,mid+1,right,Node*2+1);
}

int main(){
    scanf("%lld %lld %lld",&N,&M,&K);
    for(int i=0;i<N;i++){
        scanf("%lld",&sequence[i]);
    }
    init_seg(0,N-1,1);

    long long a,b,c;
    for(int i=0;i<M+K;i++){
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a == 1){
            update(b,c);
            //see();
        }
        else{
            cout<<calc(b-1,c-1,0,N-1,1)<<"\n";
        }
    }
}