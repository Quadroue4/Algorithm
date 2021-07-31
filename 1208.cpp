//1208.cpp

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int mid = 4000000;
int Arr[8000000]; //4백만번째가 idx=0임. 이 배열은 해당 idx가 가능한 가지수를 나타냄.
int tempArr[8000000];


void addSet(set<int>& mainSet,int newvalue){
    //fill(tempArr,tempArr+2*mid,0);
    vector<int> newvalues;

    for(auto iter = mainSet.begin();iter!=mainSet.end();iter++){
        newvalues.push_back(newvalue+*iter-mid); //idx
        tempArr[newvalue+*iter-mid] = Arr[*iter];
    }
    
    tempArr[newvalue]++;
    
    for(auto iter = mainSet.begin();iter!=mainSet.end();iter++){
        int idx = newvalue+*iter-mid;
        Arr[idx] += tempArr[idx];
    }
    mainSet.insert(newvalue);
    for(int i=0;i<newvalues.size();i++){
        mainSet.insert(newvalues[i]);
    }

    //newvalue 자체를 tempArr에 넣기
    //mainSet을 통해 tempArr에 추가
    //temp Arr값을 Arr값에 더하기
    //mainSet 업데이트
}


int main(){
    int N,S;
    cin >> N >> S;

    fill(Arr,Arr+8000000,0);

    set<int> givenSequence;
    set<int> outputSequence;

    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        Arr[mid+a]++;
        givenSequence.insert(mid+a);
    }

    for(auto iter = givenSequence.begin();iter!=givenSequence.end();iter++){
        addSet(outputSequence,*iter);
    }

    cout<<Arr[mid+S];
}