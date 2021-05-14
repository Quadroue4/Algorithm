#include <iostream>
#include <vector>
#include <string>

using namespace std;

int pi[38];
int mem[1000004]={0}; // 0번에는 0값이, str의 첫번째 문자와 몇개가 겹치는지는 mem[1]에 있음.

void get_pi(string &str){
    int j = 0;
    for(int i=1;i<str.size();i++){
        while(j>0 && str[i] != str[j])
            j = pi[j-1];
        if(str[i] == str[j])
            pi[i] = ++j;
    }
}

string string_search(string& sentence,string& word){
    int idx = 0;
    int j = 0;
    int length = word.size();
    string ans;
    for(int i=0;i<sentence.size();i++){
        ans += sentence[i];
        ++idx;
        while(j>0 && sentence[i] != word[j])
            j = pi[j-1];
        if(sentence[i] == word[j]){
            j++;
            mem[idx] = j;
            if(j == length){
                for(int k=0;k<length;k++){
                    ans.pop_back();
                    mem[idx] = 0;
                    idx--;
                }
                //cout<<ans<<" and ";
                //idx -= length;
                j = mem[idx];
                //cout<<"J is "<<j<<" ";
            }
        }
    }
    return ans;
}
int main(){
    string a,b,c;
    cin>>a>>b;
    //get_pi(b);
    c = string_search(a,b);
    //cout<<c.size()<<" ";
    if(c.size() != 0){
        cout<<c;
    }
    else
        cout<<"FRULA";
}