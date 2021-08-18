//12015.cpp

#include <iostream>
#include <algorithm>

using namespace std;

int sequence[1000001];

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
    for(int i=0;i<N;i++){
        scanf("%d",&a);
        int temp = find_idx(a,0,count);
        //cout<<"idx is "<<temp<<"\n";
        if(temp == -1)
            continue;

        sequence[temp] = a;
        if(temp == count)
            count++;
    }
/*
    for(int i=0;i<=N;i++){
        //cout<<sequence[i]<< " ";
    }
    */
    cout<<count;
}