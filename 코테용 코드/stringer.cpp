//stringer.cpp

#include<iostream>
#include<vector>
#include <cstdio>
#include <map>
#include <cstring>
#include <iterator>

using namespace std;

vector<string> split(string a,char b){
    vector<string> ans;
    string temp;
    for(int i=0;i<a.size();i++){
        if(a[i] == b){
            if(temp.size() > 0)
                ans.push_back(temp);
            temp.clear();
        }
        else{
            temp.push_back(a[i]);
        }
    }
    if(temp.size() > 0)
        ans.push_back(temp);
    return ans;
}

int main(){
    string a = "fuck u ass hole";

    vector<string> ans = split(a,' ');

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" "<<ans[i].size()<<"\n";
    }

    map<string, int> myMap;
    map<string, int>::iterator p;

    myMap.insert(pair<string, int>("Rob", 28));
    myMap["Joe"] = 1;
    myMap["Joe"] = 2;
    myMap["Sue"] = 3;
    p = myMap.find("Joe");
    if (p == myMap.end()) cout << "nonexistent\n";
        for (p = myMap.begin(); p != myMap.end(); ++p) {
            cout << "(" << p->first << "," << p->second << ")\n";
    }
    cout<<"Joes value "<<myMap["Joe"]<<"\n";
    p = myMap.find("Joe"); //iterator 반환
    myMap.erase(p);
    myMap.erase("Sue");
    p = myMap.find("Joe");
    if (p == myMap.end()) cout << "nonexistent\n";
    for (p = myMap.begin(); p != myMap.end(); ++p) {
        cout << "(" << p->first << "," << p->second << ")\n";
    }
}
