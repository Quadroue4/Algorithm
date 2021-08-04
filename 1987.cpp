//1987.cpp

#include <iostream>
#include <algorithm>

using namespace std;

int usedAlphabet=0;
int height,width;
char board[20][20];
int  DFS(int y,int x){
    if(!(0<=y && y < height && 0<=x && x < width))
        return 0;
    int num = 1<<(board[y][x]-'A');
    if( (usedAlphabet & (num)) > 0)
        return 0;
    
    usedAlphabet = usedAlphabet | (num);
    int ans = 0;
    ans = max(ans,DFS(y-1,x));
    ans = max(ans,DFS(y+1,x));
    ans = max(ans,DFS(y,x-1));
    ans = max(ans,DFS(y,x+1));
    usedAlphabet = usedAlphabet - num;
    return ans+1;
}

int main(){
    cin >> height >> width;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin >> board[i][j];
        }
    }
    int ans = DFS(0,0);
    cout << ans;
}
