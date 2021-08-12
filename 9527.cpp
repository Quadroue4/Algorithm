//9527.cpp

#include <iostream>
#include <vector>

using namespace std;

long long dp[60]; //0번째는 비워놓음.2^1-1 ~ 2^60-1승까지의 1의 개수. 0~1까지 : 1개 2~3까지 : 3개 4~7까지 : 8. An+1 = 2*An+n
long long sub;
long long sum;
string dec_to_bin(long long a){ //vec[0] = 0의자리, vec[1] = 1의자리
    string ans;
    while(a>0){
        ans.push_back(a%2);
        a /= 2;
    }
    return ans;
}

long long bin_to_dec(string a){
    int top = a.size()-1;
    long long sum1 = 0;
    while(top>=0){
        sum1 *= 2;
        sum1 += a[top];
        top--;
    }
    return sum1;
}

void do_dp(int i){
    if(i==60)
        return;
    dp[i+1] = 2*dp[i]+sub;
    sub *= 2;
    do_dp(i+1);
}

void do_sum(){
    for(int i=2;i<=60;i++){
        dp[i] += dp[i-1];
    }
}

long long number_of_one(string a){
    sum = 0;
    while(true){
        int size = a.size()-1;
        sum += dp[size]; // 0~1111...11까지는 모두 구함.
        //cout<<"first : "<<dp[size]<<" size is : "<<size<<"\n";
        int top = size-1; //제일 맨위 1을 제외한 가장큰 1을 찾아야하므로, 제일 맨위 보다 1 작은값부터 시작해야한다
        while(top>=0){
            if(a[top] == 1)
                break;
            top--;
        }
        a = a.substr(0,top+1);
        sum += bin_to_dec(a)+1; // 제일큰 1이 서브넘버의 개수에 의해 증가하는 수. ex) 10010 : 서브넘버10이 00,01,10 까지 총 3개까지 생기며 이로인해 제일큰 1이 3개 증가.
        if(top<0){//서브넘버 b가 0이면 작동안함.
            break;
        }
        //cout<<"second : "<<bin_to_dec(a)+1;
    }
    //cout<<"ans is"<<sum<<"\n";
    return sum;
}

long long counter(long long a){
    long long count = 0;
    while(a>0){
        if(a%2 == 1){
            count++;
        }
        a /= 2;
    }
    return count;
}


int main(){
    dp[0] = 0;
    dp[1] = 1;
    sub = 1;
    do_dp(1);
    do_sum();
    long long A,B;
    cin >> A >> B;

    long long numB = number_of_one(dec_to_bin(B));
    long long numA = number_of_one(dec_to_bin(A));

    //cout<<numB<<"\n";
    //cout<<numA<<"\n";
    cout<<numB-numA+counter(A);

}