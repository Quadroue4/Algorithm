//9466.cpp

#include <iostream>

using namespace std;

int N;
int hope_for_team[100001];
bool Done[100001];
int stack[100001];
int top = -1;
int count = 0;

void DeleteCycle(int i){
    for(int j=0;j<=top;j++){
        if(stack[j] == i)
            break;
        count++;
    }
}

void see(){
    cout<<"stack is : ";
    for(int i=0;i<=top;i++)
        cout<<stack[i]<<" ";
    cout<<"\n";
}

void DFS(int i){
    top = -1;
    while(true){
        if(Done[i])
            break;
        int idx = hope_for_team[i];
        Done[i] = true;
        stack[++top] = i;
        if(Done[idx]){
            //see();
            DeleteCycle(idx);
            break;
        }
        else{
            i = idx;
        }
    }
}

void do_testcase(){
    count = 0;
    cin >> N;
    for(int i=1;i<=N;i++){
        int u;
        scanf("%d", &u);
        hope_for_team[i] = u;
        Done[i] = false;
    }
    for(int i=1;i<=N;i++){
        DFS(i);
    }

    cout<<count<<"\n";
}

int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        do_testcase();
    }
}