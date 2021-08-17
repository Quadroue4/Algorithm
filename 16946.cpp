//16946.cpp

#include <iostream>

using namespace std;

int N,M;

int board[1001][1001];

int parent[1000001];

int gang[1000001];

int array_to_int(int i,int j){
    return M*i+j;
}

int get_parent(int x){
    if(x == parent[x])
        return x;
    else{
        return parent[x] = get_parent(parent[x]);
    }
}

int get_parent2(int x){
    if(x == parent[x])
        return x;
    else{
        return get_parent2(parent[x]);
    }
}

void merge(int a,int b){
    int aP = get_parent(a);
    int bP = get_parent(b);
    if(aP != bP){
        parent[bP] = aP;
        gang[aP] += gang[bP];
        gang[bP] = 0; // 의미는 없지만 ㅎ
    }
}

int how_many_gang(int y,int x){
    if(y<0 || y>=N || x<0 || x >= M)
        return 0;
    else if(board[y][x] == 0){
        return gang[get_parent(array_to_int(y,x))];
    }
    return 0;
}

void try_merge(int y,int x){
    if(y>0 && board[y-1][x] != 1)
        merge(array_to_int(y,x),array_to_int(y-1,x));

    if(y<N-1 && board[y+1][x] != 1)
        merge(array_to_int(y,x),array_to_int(y+1,x));

    if(x>0 && board[y][x-1] != 1)
        merge(array_to_int(y,x),array_to_int(y,x-1));

    if(x<M-1 && board[y][x+1] != 1)
        merge(array_to_int(y,x),array_to_int(y,x+1));
}

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        string a;
        cin >> a;
        for(int j=0;j<M;j++){
            board[i][j] = a[j] - '0';
            if(board[i][j] == 0){
                parent[array_to_int(i,j)] = array_to_int(i,j);
                gang[array_to_int(i,j)] = 1;
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(board[i][j] == 0)
                try_merge(i,j);
        }
    }
    /*
    cout<<"\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<gang[array_to_int(i,j)]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    */

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(board[i][j] == 1){
                int count = 0;
                int temp[4];
                for(int k=0;k<4;k++)
                    temp[k] = -1;
                int tmp = how_many_gang(i-1,j);

                if(tmp>0)
                    temp[0] = get_parent(array_to_int(i-1,j));
                count+=tmp;

                tmp = how_many_gang(i+1,j);
                if(tmp>0){
                    int num = get_parent(array_to_int(i+1,j));
                    if(temp[0] != num ){
                        temp[1] = num;
                        count+=tmp;
                    }
                }

                tmp = how_many_gang(i,j-1);
                if(tmp>0){
                    int num = get_parent(array_to_int(i,j-1));
                    if(temp[0] != num && temp[1] != num ){
                        temp[2] = num;
                        count+=tmp;
                    }
                }

                tmp = how_many_gang(i,j+1);
                if(tmp>0){
                    int num = get_parent(array_to_int(i,j+1));
                    if(temp[0] != num && temp[1] != num && temp[2] != num){
                        temp[3] = num;
                        count+=tmp;
                    }
                }
                cout<<(count+1)%10;
            }
            else{
                cout<<0;
            }
        }
        cout<<"\n";
    }


}