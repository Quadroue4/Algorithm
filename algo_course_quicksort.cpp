//algo_course_quicksort

#include <iostream>

using namespace std;

int arr1[1000];
int arr2[1000];
int N;
pair<int,int> Hoarequicksort(int i,int j){
    int swapc = 0;
    int comp = 0;
    
    if(i>=j)
        return {0,0};
    
    int pivot = arr1[i];
    
    int left = i-1;
    int right = j+1;
    
    while(true){
        
        do{
            left++;
            comp++;
        }while(arr1[left] < pivot);
        
        do{
            right--;
            comp++;
        }while(arr1[right] > pivot);
        
        if(left >= right)
            break;

        int temp = arr1[left];
        arr1[left] = arr1[right];
        arr1[right] = temp;
        swapc++;
    }
    
    pair<int,int> info_left = Hoarequicksort(i,right);
    pair<int,int> info_right = Hoarequicksort(right+1,j);
    
    return {info_left.first+info_right.first+swapc,info_left.second+info_right.second+comp};
}

void see(){
    cout<<"\n";
    for(int i=0;i<N;i++)
        cout<<arr1[i]<<" ";
    cout<<"\n";
    for(int i=0;i<N;i++)
        cout<<arr2[i]<<" ";
    cout<<"\n";
}

pair<int,int> Lomutoquicksort(int i,int j){
    if(i >= j)
        return {0,0};
    int left = i;
    int pivot = arr2[i];
    int comp = 0;
    int swapc = 0;
    for(int right=i+1;right<=j;right++){
        comp++;
        if(arr2[right] < pivot){
            left ++;
            int temp = arr2[left];
            arr2[left] = arr2[right];
            arr2[right] = temp;
            swapc++;
        }
    }
    int temp = arr2[left];
    arr2[left] = arr2[i];
    arr2[i] = temp;
    swapc++;

    pair<int,int> info_left = Lomutoquicksort(i,left-1);
    pair<int,int> info_right = Lomutoquicksort(left+1,j);
    
    return {info_left.first+info_right.first+swapc,info_left.second+info_right.second+comp};
}

void Solve(){
    cin >> N;
    for(int i=0;i<N;i++){
        scanf("%d",&arr1[i]);
        arr2[i] = arr1[i];

    }
    pair<int,int> Hoareinfo = Hoarequicksort(0,N-1);
    
    pair<int,int> Lomutoinfo = Lomutoquicksort(0,N-1);

    cout<<Hoareinfo.first<<" "<<Lomutoinfo.first<<" "<<Hoareinfo.second<<" "<<Lomutoinfo.second<<"\n";
    //see();
}

int main(){
    int T;
    cin >> T;
    
    for(int i=0;i<T;i++){
        Solve();
    }
}