//2357.cpp

#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
pair<int,int> segment_tree[400001];
int sequence[100000];

pair<int,int> init_seg(int start,int end,int Node){
    if(start == end){
        int value = sequence[start];
        segment_tree[Node] = {value,value};
        return {value,value};
    }
    int mid = (start+end)/2;
    pair<int,int> left = init_seg(start,mid,Node*2);
    pair<int,int> right = init_seg(mid+1,end,Node*2+1);

    return segment_tree[Node] = {min(left.first,right.first),max(left.second,right.second)};
}

pair<int,int> query(int start,int end,int left,int right,int Node){
    if(start == left && end == right){
        return segment_tree[Node];
    }
    int mid = (left+right)/2;
    
    if(end <= mid){
        return query(start,end,left,mid,2*Node);
    }
    if(mid < start){
        return query(start,end,mid+1,right,2*Node+1);
    }
    pair<int,int> leftP = query(start,mid,left,mid,2*Node);
    pair<int,int> rightP = query(mid+1,end,mid+1,right,2*Node+1);
    
    return {min(leftP.first,rightP.first),max(leftP.second,rightP.second)};
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d",&sequence[i]);
    }
    init_seg(0,N-1,1);
    int a,b;
    for(int i=0;i<M;i++){
        scanf("%d %d",&a,&b);
        pair<int,int> ans = query(a-1,b-1,0,N-1,1);
        cout<<ans.first<<" "<<ans.second<<"\n";
    } 
}