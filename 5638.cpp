#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int preorder[10005] = {};

void postorder(int s,int e){
    if(s>e)
        return;
    auto it = upper_bound(preorder + s, preorder + e, preorder[s]);
    int dis = distance(preorder,it);
    postorder(s+1,dis-1);
    postorder(dis,e);
    cout<<preorder[s]<<"\n";

}

int main(){
    cin.tie(0);
	ios::sync_with_stdio(0);
    int count = 0;
    while(cin >> preorder[count++]);

    postorder(0,count-1);
}