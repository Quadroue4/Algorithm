//3015.cpp

#include <iostream>
#include <stack>

using namespace std;

int sequence[500000];
stack<pair<int,int>> people; //height,num
int N;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&sequence[i]);
    }

    long long ans = 0;
    people.push({sequence[0],1});
    int idx = 1;
    while(idx < N){
        int newPerson = sequence[idx];
        if(people.top().first > newPerson){
            //cout<<"new person is smaller";
            ans += 1;
            people.push({newPerson,1});
        }
        else{
            //cout<<"new person is same or bigger";
            int value = 0;
            while(people.size() > 0 && people.top().first <= newPerson){
                ans += people.top().second;
                value = 0;
                if(people.top().first == newPerson){
                    value = people.top().second;
                    people.pop();
                    break;
                }
                else{
                    people.pop();
                }
            }
            if(people.size()>0)
                ans++;
            people.push({newPerson,value+1});
        }
        //cout<<"\n";
        //cout<<"new : "<<newPerson<<" ans : "<<ans<<" idx : "<<idx<<"\n";
        idx++;
    }
    cout<<ans;
}