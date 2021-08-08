//2473.cpp

//2467.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long sequence[5000];
long long mini = 3000000001;
int N;
int first;
int minusSave;
int plusSave;

void func(int fixedNum){
    int minusPointer = fixedNum+1;
    int plusPointer = N-1;
    bool judge = true;

    while(judge){
        if(sequence[plusPointer] + sequence[fixedNum] + sequence[minusPointer] > 0){
            if(minusPointer+1<plusPointer){
                plusPointer--;
            }
            else
                judge = false;
        }
        else if(sequence[plusPointer] + sequence[fixedNum] + sequence[minusPointer] < 0){
            if(minusPointer+1<plusPointer){
                minusPointer++;
            }
            else
                judge = false;
        }
        else{
            judge = false;
        }
        if(mini >= abs(sequence[fixedNum] + sequence[minusPointer] + sequence[plusPointer])){
            first = fixedNum;
            minusSave = minusPointer;
            plusSave = plusPointer;
            mini = abs(sequence[fixedNum] + sequence[minusPointer] + sequence[plusPointer]);
            //cout<<sequence[first]<<" "<<sequence[minusSave]<<" "<<sequence[plusSave]<<"\n";
        }
    }
}

int main(){
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> sequence[i];
    }
    sort(sequence,sequence+N);
    first = 0;
    minusSave = 1;
    plusSave = N-1;

    for(int i=0;i<N-2;i++){
        mini = min(mini,abs(sequence[i]+sequence[i+1]+sequence[N-1]));
        func(i);
    }
    
    cout<<sequence[first]<<" "<<sequence[minusSave]<<" "<<sequence[plusSave];
}