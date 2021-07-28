//1007.cpp

#include <iostream>
#include <vector>
#include <cmath>
#include <float.h>

using namespace std;

long long distance(pair<double,double> a,pair<double,double> b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

pair<double,double> mid = {0,0};
vector<pair<double,double>> vecPoint;

int N;
long long vecComb(int current,int selected){
    if(selected == N/2)
        return distance(mid,{0,0});
    if(current == N)
        return 9223372036854775807;
    long long sum1,sum2 = 0;
    mid.first -= 2*vecPoint[current].first;
    mid.second -= 2*vecPoint[current].second;
    sum1 = vecComb(current+1,selected+1);

    mid.first += 2*vecPoint[current].first;
    mid.second += 2*vecPoint[current].second;
    sum2 = vecComb(current+1,selected);

    if(sum1<sum2)
        return sum1;
    return sum2;
}

int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        mid = {0,0};
        cin >> N;
        vecPoint.clear();

        for(int j=0;j<N;j++){
            double a,b;
            cin >> a >> b;
            vecPoint.push_back({a,b});
            mid.first = mid.first+a;
            mid.second = mid.second+b;

        }
        long long ans = vecComb(0,0);
        cout << std::fixed;
		cout.precision(15);

        cout<<sqrt(ans)<<"\n";
        //cout << fixed;
        //cout << precision(n)
        //cout << fixed 를 추가하면 소수점 이하의 자릿수만 다룰 수 있게 된다. 소수점 이하의 n 개의 수를 나타낼 것이란 말이다.
    }
}