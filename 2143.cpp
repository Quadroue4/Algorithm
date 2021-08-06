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

    long long ans = 0;

    for(int i=0;i<nsA.size();i++){
        int remain = T-nsA[i];

       auto l = lower_bound(msA.begin(),msA.end(),remain);
       auto r = upper_bound(msA.begin(),msA.end(),remain);
       ans += r-l;
    }

    cout<<ans;
}