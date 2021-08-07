//2239.cpp

#include <iostream>

using namespace std;

int HorizontalSudoku[9];
int VerticalSudoku[9];
int SqureSudoku[3][3];

int board[9][9];

void see(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j];
        }
        cout<<"\n";
    }
}

bool check(int y,int x,int num){
    int bit = (1<<(num-1));
    if( ((HorizontalSudoku[y] & bit) > 0) || ((VerticalSudoku[x] & bit) > 0) || ((SqureSudoku[y/3][x/3] & bit) > 0) )
        return false;
    return true;
}

void bit_add(int y,int x,int num){
    int bit = (1<<(num-1));
    HorizontalSudoku[y] = (HorizontalSudoku[y] | bit);
    VerticalSudoku[x] = (VerticalSudoku[x] | bit);
    SqureSudoku[y/3][x/3] = (SqureSudoku[y/3][x/3] | bit);
}

void bit_minus(int y,int x,int num){
    int bit = (1<<(num-1));
    HorizontalSudoku[y] = (HorizontalSudoku[y] - bit);
    VerticalSudoku[x] = (VerticalSudoku[x] - bit);
    SqureSudoku[y/3][x/3] = (SqureSudoku[y/3][x/3] - bit);
}

bool DFS(int y,int x){
    if(y<9 && x == 9){
        if(y<8)
            return DFS(y+1,0);
        else{
            return true; //9,10까지 갔다는건 9,9까지 완성했다는 소리이므로 완료.
        }
    }
    if(board[y][x] != 0)
        return DFS(y,x+1);
    
    for(int i=1;i<=9;i++){
        if( check(y,x,i) ){
            bit_add(y,x,i);
            board[y][x] = i;
            if(DFS(y,x+1))
                return true;
            bit_minus(y,x,i);
            board[y][x] = 0;
        }
    }
    return false;
}

int main(){
    for(int i=0;i<9;i++){
        string a;
        cin >> a;
        for(int j=0;j<9;j++){
            board[i][j] = a[j] - '0';
            if(board[i][j] != 0){
                bit_add(i,j,board[i][j]);
            }
        }
    }
    DFS(0,0);

    see();
}