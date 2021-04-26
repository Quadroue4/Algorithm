#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int pi[10000000];

int index_information[10000000];
int total_count = 0;
void getpi(string &p) {
	int n = p.size();
	int j = 0;
	for (int i = 1; i < n; i++) {
		while (j > 0 && p[j] != p[i])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
}
void kmp(string &s, string &p) {
	getpi(p);
	int n = s.size();
	int m = p.size();
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				index_information[total_count++] = i - j;
				j = pi[j];
			}
			else
				j++;
		}
	}
}


	int main()
	{
		for (int i = 0; i < 10000000; i++)
			pi[i] = 0;
		string input1, input2;
		//cin >> input1 >> input2;
		getline(cin, input1);
		getline(cin, input2);

		kmp(input1, input2);

		cout << total_count << "\n";
		for (int i = 0; i < total_count; i++)
			cout << index_information[i] + 1 << " ";

		return 0;
	}