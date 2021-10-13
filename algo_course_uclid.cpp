//algo_course_uclid.cpp

#include <iostream>

using namespace std;

int gcd(int a,int b){
    if(a < b){
        int temp = a;
        a = b;
        b = temp;
    }
    // a > b

    if(b == 0)
        return a;
    
    return gcd(b,a%b);
}


void solve(){
    int a,b;
    cin >> a >> b;
    cout<<gcd(a,b)<<"\n";
}

int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        solve();
    }
}