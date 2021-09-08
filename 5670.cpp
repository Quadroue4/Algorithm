//5670.cpp

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

string strings[100000];
int collap[100000];

int collapse(string &a,string &b){
    int count = 0;
    for(int i=0;i<min(a.size(),b.size());i++){
        if(a[i] != b[i])
            break;
        count++;
    }
    return count;
}

int search(int current,int depth,int start,int end){
    if(start == end){
        return depth;
    }
    int test = 2099999999;
    
    
    for(int i=start;i<end;i++){
        test = min(test,collap[i]-current);
    }

    if(test>0)
        return search(current+test,depth,start,end);

    int mini;
    int mini2 = 2099999999;
    int temp = start;
    int ans = 0;

    if(current == strings[start].size()){
        ans += depth;
        temp++;
    }

    for(int i=temp;i<end;i++){
        mini = collap[i]-current;
        if(mini != 0)
            mini2 = min(mini,mini2);
        else if(mini == 0){
            ans += search(current+mini2,depth+1,temp,i);
            temp = i+1;
            mini2 = 2099999999;
        }
    }
    for(int i=temp;i<end;i++)
        mini2 = min(mini2,collap[i]-current);
    ans += search(current+mini2,depth+1,temp,end);
    return ans;
}

void solve(int t){
    for(int i=0;i<t;i++){
        char temp[81];
        scanf("%s",temp);
        strings[i] = temp;
    }

    sort(strings,strings+t);

    for(int i=0;i<t-1;i++){
        collap[i] = collapse(strings[i],strings[i+1]);
    }

    int temp = 0;
    int ans = 0;
    for(int i=0;i<t-1;i++){
        if(collap[i] == 0){
            ans += search(1,1,temp,i);
            temp = i+1;
        }
    }
    ans += search(1,1,temp,t-1);

    cout<<fixed;
    cout.precision(2);
    cout<<ans/(double)t<<'\n';
}

int main(){
    int T;
    while(scanf("%d",&T)>0){
        solve(T);
    }
}