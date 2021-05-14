#include <iostream>
#include <vector>
#include <string>

using namespace std;

int pi[36];
vector<int> idx;
void get_pi(string &str){
    int j = 0;
    for(int i=1;i<str.size();i++){
        while(j>0 && str[i] != str[j])
            j = pi[j-1];
        if(str[i] == str[j])
            pi[i] = ++j;
    }
}

void string_search(string& sentence,string& word){
    int j = 0;
    for(int i=0;i<sentence.size();i++){
        while(j>0 && sentence[i] != word[j])
            j = pi[j-1];
        if(sentence[i] == word[j]){
            j++;
            if(j == word.size()){
                idx.push_back(i-(j-1));
                j = 0;
            }
        }
    }
}
int main(){
    string a,b;
    cin>>a>>b;
    get_pi(b);
    do{
        idx.clear();
        string_search(a,b);
        if(idx.size() == 0)
            break;
        int length = b.size();
        string temp;
        auto it = a.begin();
        temp.insert(temp.end(),it,it+idx[0]); // 첫 idx 바로전까지 복사.
        for(int i=0;i<idx.size()-1;i++){
            temp.insert(temp.end(),it+idx[i]+length,it+idx[i+1]); //
        }
        if(idx[idx.size()-1]+length < a.size())
            temp.insert(temp.end(),it+idx[idx.size()-1]+length,a.end());
        a = temp;
    }while(true);
    if(a.size()>0)
        cout<<a;
    else
        cout<<"FRULA";
}