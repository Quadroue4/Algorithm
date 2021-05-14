#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
int arr[1000][1000];
string a,b;

int lcs(int i,int j){
    int idx = 0;
    if(i>=a.size() || j>=b.size())
        return 0;
    if(arr[i][j] != -1)
        return arr[i][j];
    while(j+idx < b.size() && a[i] != b[j+idx])
        idx++;
    int sum1=0;int sum2=0;int sum3=0;

    if(j+idx < b.size())
        sum1++;
    
    sum1 += lcs(i+1,j+idx+1);
    idx = 0;

     while(i+idx < a.size() && a[i+idx] != b[j])
        idx++;

    if(i+idx < a.size())
        sum2++;
        
    sum2 += lcs(i+idx+1,j+1);
    sum3 = lcs(i+1,j+1);
    arr[i][j] = max(max(sum1,sum2),sum3);

    return arr[i][j];
    
}


int main(){
    cin >> a >> b;
    for(int i=0;i<1000;i++)
        for(int j=0;j<1000;j++)
            arr[i][j] = -1;
    int ans = lcs(0,0);
    cout<<ans;
}