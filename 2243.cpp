//2243.cpp

#include <iostream>
#define Taste 1000000
using namespace std;

int N;
int A,B,C;
int segment_tree[Taste*4];

void put_with_taste(int start,int end,int taste,int num,int Node){
    if(taste < start || end < taste)
        return;
    
    segment_tree[Node] += num;

    if(start == end){
        return;
    }

    int mid = (start+end)/2;
    put_with_taste(start,mid,taste,num,Node*2);
    put_with_taste(mid+1,end,taste,num,Node*2+1);
}

void get_with_rank(int start,int end,int rank,int Node){
    //cout<<"start : "<<start<<" end : "<<end<<" rank : "<<rank<<" Node num : "<<Node<<" left num : "<<segment_tree[Node*2]<<" right num : "<<segment_tree[Node*2+1]<<"\n";
    int mid = (start+end)/2;

    if(start == end){
        put_with_taste(0,Taste-1,end,-1,1);
        cout<<end+1<<"\n";
    }

    else if(rank <= segment_tree[Node*2]){
        get_with_rank(start,mid,rank,2*Node);
    }

    else{
        get_with_rank(mid+1,end,rank-segment_tree[2*Node],2*Node+1);
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d %d",&A,&B);
        if(A==2){
            scanf("%d",&C);
            put_with_taste(0,Taste-1,B-1,C,1);
        }
        else{
            get_with_rank(0,Taste-1,B,1);
        }
    }
}