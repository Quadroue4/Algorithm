//2467.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sequence[200000];
int mini = 2000000001;
int main(){
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> sequence[i];
    }

    int minusPointer = 0;
    int plusPointer = N-1;

    int minusSave = minusPointer;
    int plusSave = plusPointer;
    mini = abs(sequence[plusPointer]+sequence[minusPointer]);

    while(true){
        if(abs(sequence[plusPointer]) > abs(sequence[minusPointer])){
            if(minusPointer+1<plusPointer){
                plusPointer--;
            }
            else
                break;
        }
        else{
            if(minusPointer+1<plusPointer){
                minusPointer++;
            }
            else break;
        }

        if(mini >= abs(sequence[plusPointer]+sequence[minusPointer])){
            minusSave = minusPointer;
            plusSave = plusPointer;
            mini = abs(sequence[plusPointer]+sequence[minusPointer]);
        }
    }

    cout<<sequence[minusSave]<<" "<<sequence[plusSave];
}