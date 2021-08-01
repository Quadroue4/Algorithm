//1509-1.cpp

#include <iostream>
#include <vector>
#include <string>

using namespace std;



int palindrome[2500][2500];

void makeAllpalindrome(string& str,int start,int end){
    
    for(int i=0;start+i<=end-i;i++){
        palindrome[start+i][end-i] = 1;
    }
    
}

bool is_palindrome(string& str,int start,int end){
    int ans = palindrome[start][end];
    if(ans != -1){
        if(ans == 1)
            return true;
        else
            return false;
    }
    bool judge = true;
    int length = end-start+1;
    for(int i=0;i<length/2;i++){
        if(str[start+i] != str[end-i]){
            judge = false;
            break;
        }
    }

    if(judge){
        makeAllpalindrome(str,start,end);
    }
    else{
        palindrome[start][end] = 2;
    }
    return judge;
}

void getpalindrome(string& input,vector<vector<int>>& cordinate)
{
    for(int i=0;i<input.size();i++){
        vector<int> temp;
        for(int j=input.size()-1;j>=0;j--){
            if(is_palindrome(input,i,j))
                temp.push_back(j);
        }
        cordinate.push_back(temp);
    }
}



int main(){
    string input;
    vector<vector<int>> cordinate;
    cin >> input;

    for(int i=0;i<input.size();i++)
        for(int j=0;j<input.size();j++)
            palindrome[i][j] = -1;
    getpalindrome(input,cordinate);
    /*
    for(int i=0;i<cordinate.size();i++){
        for(int j=0;j<cordinate[i].size();j++){
            cout<<cordinate[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
    int palindromeValues[2500];
    fill(palindromeValues,palindromeValues+2500,-1);

    for(int i=0;i<cordinate[0].size();i++){
        int temp = cordinate[0][i];
        palindromeValues[temp] = 1;
    }

    for(int i=1;i<cordinate.size();i++){
        int value = palindromeValues[i-1]+1;
        for(int j=0;j<cordinate[i].size();j++){
            int temp = cordinate[i][j];
            if(palindromeValues[temp] == -1 || palindromeValues[temp] > value)
                palindromeValues[temp] = value;
        }
    }

    cout<<palindromeValues[input.size()-1];
}