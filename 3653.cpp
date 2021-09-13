//3653.cpp
#include <iostream>
#include <vector>

using namespace std;

int movie_idx[100001];
int segment_tree[800001];
int new_idx;
int n,m;

int init_seg(int start,int end,int Node){
    if(start == end){
        if(start>=m){
            movie_idx[start-m+1] = Node;
            return segment_tree[Node] = 1;
        }
        else{
            return segment_tree[Node] = 0;
        }
    }
    
    int left = init_seg(start,(start+end)/2,Node*2);
    int right = init_seg((start+end)/2+1,end,Node*2+1);

    return segment_tree[Node] = left+right;
}

int find_idx(int num,int start,int end,int Node){
    //cout<<num<<" "<<start<<" "<<end<<" "<<Node<<"\n";
    int mid = (start+end)/2;
    if(start == end)
        return Node;
    if(num <= mid){
        return find_idx(num,start,mid,Node*2);
    }
    else
        return find_idx(num,mid+1,end,Node*2+1);
}


int calc(int idx){
    int tmpidx;
    int sum = 0;
    while(idx > 1){
        tmpidx = idx / 2;
        if(tmpidx*2 < idx){ //idx가 tmp의 오른쪽 노드일때만
            sum += segment_tree[tmpidx*2];
        }
        idx /= 2; 
    }
    return sum;
}

void update_seg(int idx,int num){
    segment_tree[idx] = num;
    while(idx>=2){ //root(1)에서 끝나므로
        idx /= 2;
        segment_tree[idx] = segment_tree[idx*2] + segment_tree[idx*2+1];
    }
}

int find_movie(int a){
    int idx = movie_idx[a];
    int total = calc(idx);
    update_seg(idx,0);
    int temp = find_idx(new_idx,0,n+m-1,1);
    new_idx--;
    movie_idx[a] = temp;
    update_seg(temp,1);
    return total;
}

void solve(){
    cin >> n >> m;
    init_seg(0,n+m-1,1);
    new_idx = m-1;
    vector<int> ans;
    for(int i=0;i<m;i++){
        int a;
        cin >> a;
        ans.push_back(find_movie(a));
    }

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
}


int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        solve();
    }
}