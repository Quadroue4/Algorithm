//16724.cpp

#include <iostream>

using namespace std;

char board[1000][1000];

int parent[1000000];
bool used[1000000];
int N,M;

int get_parent(int x){
    if(x == parent[x])
        return x;
    else{
        return parent[x] = get_parent(parent[x]);
    }
}

int array_to_int(int y,int x){
    return M*y+x;
}

void merge(int x,int y){ // y를 x에 종속.
    int xP = get_parent(x);
    int yP = get_parent(y);
    if(xP != yP)
        parent[yP] = xP;
}

void make_cycle(int y,int x){
    if(board[y][x] == 'U'){
        merge(array_to_int(y-1,x),array_to_int(y,x));
    }
    else if(board[y][x] == 'D'){
        merge(array_to_int(y+1,x),array_to_int(y,x));
    }
    else if(board[y][x] == 'L'){
        merge(array_to_int(y,x-1),array_to_int(y,x));
    }
    else{
        merge(array_to_int(y,x+1),array_to_int(y,x));
    }
}

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            parent[array_to_int(i,j)] = array_to_int(i,j);
    for(int i=0;i<N;i++){
        string a;
        cin >> a;
        for(int j=0;j<M;j++){
            board[i][j] = a[j];
            make_cycle(i,j);
        }
    }
    int count = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            //cout<<parent[array_to_int(i,j)]<<" ";
            if( used[ get_parent( array_to_int(i,j) ) ] == false){
                used[ get_parent( array_to_int(i,j) ) ] = true;
                count++;
            }
        }
        //cout<<"\n";
    }
    
    cout<<count;
}