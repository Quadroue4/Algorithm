//1086.cpp

#include <iostream>
#include <cmath>

using namespace std;

int N;
int K;
int sequence[15][2];
long long dp[1<<15][100];
int restof_10[750];
int temp[15];

long long gcd(long long a, long long b) {
    long long r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int number_of_digits(int bit){
    for(int i=0;i<N;i++)
        temp[i] = 0;
    int idx = 0;
    while(bit>0){
        temp[idx++] = bit%2;
        bit /= 2;
    }
    int sum = 0;
    for(int i=0;i<N;i++){
        if(temp[i] == 1)
            sum += sequence[i][1];
    }
    return sum;
}

void rest_of_10(){
    int a = 1;
    for(int i=0;i<750;i++){
        restof_10[i] = a;
        a *= 10;
        a %= K;
    }
}

void do_dp(int n){
    bool judge = false;
    for(int i=0;i<K;i++){
        if(dp[n][i] != 0) //하나라도 0이 아니면 dp[n]은 처리된 친구이다. 따라서 같은연산을 여러번 할 필요가 없다. dp[0][0] = 1 이므로 n=0일때도 처리된다.
            return;
    }

    int digits = restof_10[number_of_digits(n)];
    for(int i=0;i<N;i++)
        temp[i] = 0;
    int idx = 0;
    int m = n;
    while(m>0){
        temp[idx++] = m%2;
        m /= 2;
    }
    for(int i=0;i<N;i++){
        if(temp[i] == 1){
            do_dp(n-(1<<i));
            int digit = number_of_digits(n-(1<<i));
            int plus = (restof_10[digit]*sequence[i][0]);
            for(int j=0;j<K;j++){
                dp[n][ (j + plus)%K ]  += dp[ n- (1<<i) ][j];
            }
        }
    }
}

int string_to_int(string& temp){
    int sum = 0;
    for(int i=0;i<temp.size();i++){
        sum *= 10;
        sum += temp[i]-'0';
        sum = sum%K;
    }
    return sum;
}

int main(){
    cin >> N;
    string sequenceArr[15];
    for(int i=0;i<N;i++){
        cin >> sequenceArr[i];
        sequence[i][1] = sequenceArr[i].size();//자리수 저장 100이면 3, 10이면 2 이런식
    }
    cin >> K;
    for(int i=0;i<N;i++){
        sequence[i][0] = string_to_int(sequenceArr[i]); //K로 나눈 나머지를 저장
    }
    rest_of_10();

    dp[0][0] = 1;
    do_dp((1<<N)-1);
    long long bunja = dp[(1<<N)-1][0];
    long long bunmo = 1;
    for(int i=2;i<=N;i++)
        bunmo *= i;

    long long temp = gcd(bunmo,bunja);

    cout<<bunja/temp<<"/"<<bunmo/temp;
}