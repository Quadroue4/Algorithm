//1208-1.cpp

//1208.cpp

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int mid = 4000000;
long long Arr[8000001]; //4백만번째가 idx=0임. 이 배열은 해당 idx가 가능한 가지수를 나타냄.
long long tempArr[8000001];

int main(){
    int N,S;
    cin >> N >> S;

    fill(Arr,Arr+8000001,0);
    fill(tempArr,tempArr+8000001,0);

    vector<int> mainSet;

    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        mainSet.push_back(a);
    }

    for(int i=0;i<N;i++){
        int newvalue = mainSet[i];
        for(int j=0;j<8000001;j++){
            if(j+newvalue >=0 && j+newvalue <8000001)
                tempArr[j+newvalue] = Arr[j]; 
        }

        for(int j=0;j<newvalue;j++)
            tempArr[j] = 0;

        for(int j=8000001+newvalue;j<8000001;j++)
            tempArr[j] = 0;

         for(int j=0;j<8000001;j++){
            Arr[j] += tempArr[j];
        }
        Arr[mid+newvalue]++;
    }
    cout<<Arr[mid+S];
}