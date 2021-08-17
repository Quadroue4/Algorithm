//14939.cpp

#include <iostream>
#include <algorithm>

using namespace std;

char board[10][10];
char tempBoard[10][10];

void change(int y,int x){
    if(y>=0 && y< 10 && x >= 0 && x < 10){
        if(tempBoard[y][x] == '#')
            tempBoard[y][x] = 'O';

        else if(tempBoard[y][x] == 'O')
            tempBoard[y][x] = '#';
    }
}

void turn_on(int y,int x){
    change(y-1,x);
    change(y+1,x);
    change(y,x-1);
    change(y,x+1);
    change(y,x);
}

void copy(){
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            tempBoard[i][j] = board[i][j];
}

void see(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)
            cout<<tempBoard[i][j];
        cout<<"\n";
    }
}

int main(){
    for(int i=0;i<10;i++){
        string a;
        cin >> a;
        for(int j=0;j<10;j++){
            board[i][j] = a[j];
        }
    }
    
    int count = 0;
    int ans = 9999999;
    bool judge = true;
    bool realjudge= false;

    for(int k=0;k<1024;k++){
        copy();
        int bit = k;
        int pos = 0;
        count = 0;
        judge = true;
        while(bit > 0){
            if(bit%2 == 1){
                turn_on(0,pos);
                count++;
            }
            pos++;
            bit /= 2;
        }
        for(int i=1;i<10;i++){
            for(int j=0;j<10;j++){
                if(tempBoard[i-1][j] == 'O'){
                    turn_on(i,j);
                    count++;
                }
            }
        }
        for(int i=0;i<10;i++){
            if(tempBoard[9][i] == 'O')
                judge= false;
        }
        if(judge){
            ans = min(ans,count);
            realjudge = true;
            //cout<<"\n"<<ans<<"\n";
            //see();
        }
        
    }

    if(realjudge)
        cout<<ans;
    else
        cout<<-1;
}