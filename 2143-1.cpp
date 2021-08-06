//2143-1.cpp

//2143.cpp

/*
5
4
1 3 1 2
3
1 3 2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int,int> which_idx(vector<int>& a,int b){
    int start = 0;
    int end = a.size()-1;
    int idx=(end+start)/2;
    int left;
    while(true){
        if(a[idx] < b){
            start = idx+1;
            idx = (end+start)/2;
        }
        else if(a[idx] >= b){
            end = idx;
            idx = (end+start)/2;
        }
        if(end == start){
            left = idx;
            break;
        }
    }

    start = 0;
    end = a.size()-1;
    idx = (end+start)/2;
    int right;

    while(true){
        if(a[idx] <= b){
            start = idx+1;
            idx = (end+start)/2;
        }
        else if(a[idx] > b){
            end = idx;
            idx = (end+start)/2;
        }
        if(end == start){
            right = idx;
            break;
        }
    }
    return make_pair(left,right);
}

int main(){
    int T;
    cin >> T;
    int N,M;
    int sum;
    vector<int> ns,ms,nsA,msA;
    cin >> N;
    sum = 0;
    ns.push_back(0);
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        sum += a;
        ns.push_back(sum);
    }
    cin >> M;
    sum = 0;
    ms.push_back(0);
    for(int i=0;i<M;i++){
        int a;
        cin >> a;
        sum += a;
        ms.push_back(sum);
    }

    for(int i=0;i<N;i++){
        for(int j=i+1;j<=N;j++){
            nsA.push_back(ns[j] - ns[i]);
        }
    }

    for(int i=0;i<M;i++){
        for(int j=i+1;j<=M;j++){
            msA.push_back(ms[j] - ms[i]);
        }
    }

    sort(nsA.begin(),nsA.end());
    sort(msA.begin(),msA.end());
    msA.push_back(msA[msA.size()-1]+1);


    long long ans = 0;

    auto temp = which_idx(nsA,10);

    for(int i=0;i<nsA.size();i++){
        int remain = T-nsA[i];
        auto temp = which_idx(msA,remain);
        ans += temp.second-temp.first;
    }

    cout<<ans;
}