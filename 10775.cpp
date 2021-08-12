//10775.cpp

#include <iostream>

using namespace std;

bool usedGate[100001];
int availableGate[100001];

int try_Landing(int gate){
    if(availableGate[gate] == gate){
        int temp = availableGate[gate];
        availableGate[gate] = availableGate[gate-1];
        return temp;
    }
    if(availableGate[gate] != gate){
        int temp = try_Landing(availableGate[gate]);
        availableGate[gate] = temp-1;
        return temp;
    }
}

int main(){
    int G,P,gi;

    cin >> G >> P;

    int count = 0;

    for(int i=0;i<=G;i++)
        availableGate[i] = i;

    for(int i=0;i<P;i++){
        cin >> gi;
        if(try_Landing(gi) > 0)
            count++;
        else{
            break;
        }
    }
    cout<<count;
}