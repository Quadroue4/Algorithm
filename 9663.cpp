#include <iostream>
#include <vector>
using namespace std;

vector<int> qn;

bool can_put(int h,int w){
    for(int i=0;i<qn.size();i++){
        if(qn[i] + (h-i) == w or w+(h-i) == qn[i] or qn[i] == w)
            return false;
    }
    return true;
}

int queen(int i,int n){
    int sum = 0;
    if(i==n)
        return 1;
    for(int j=0;j<n;j++){
        if(can_put(i,j)){
            qn.push_back(j);
            sum += queen(i+1,n);
            qn.pop_back();
        }
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    int ans = queen(0,n);
    cout << ans;
}