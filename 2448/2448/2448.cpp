// 2448.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;
vector<pair<int, int>> arr[11];

vector<pair<int, int>>& put(vector<pair<int, int>>& a, int length) {
	vector<pair<int, int>> b;
	for (int i = 0; i < (int)a.size(); i++) {
		b.push_back(make_pair(a[i].first, a[i].second + length));
		b.push_back(make_pair(a[i].first + length, a[i].second));
		b.push_back(make_pair(a[i].first + length, a[i].second + 2* length));
	}
	return b;
}
void recursion(int k,int idx) {
	if (k>idx)
		return;
	int length = 3*pow(2, k-1);
	arr[k] = put(arr[k - 1], length);;
	recursion(k + 1,idx);
}

int main()
{


	arr[0].push_back(make_pair(0, 2));
	arr[0].push_back(make_pair(1, 1));
	arr[0].push_back(make_pair(1, 3));
	arr[0].push_back(make_pair(2, 0));
	arr[0].push_back(make_pair(2, 1));
	arr[0].push_back(make_pair(2, 2));
	arr[0].push_back(make_pair(2, 3));
	arr[0].push_back(make_pair(2, 4));

	int n;
	cin >> n;

	int idx;
	for(int i=0;i<=10;i++)
		if (pow(2, i) == n/3) {
			idx = i;
			break;
		}
	recursion(1,idx);
	char** p;
	string* no;
	no = new string[n];
	p = new char*[n];
	for (int i = 0; i < n; i++) {
		p[i] = new char[2 * n - 1];
		for (int j = 0; j < 2 * n - 1; j++) {
			p[i][j] = ' ';
			no[i] += ' ';
		}
	}

	for (int i = 0; i < arr[idx].size(); i++) {
		auto temp = arr[idx][i];
		auto a = temp.first;
		auto b = temp.second;
		p[a][b] = '*';
		no[a][b] = '*';
	}

	for (int i = 0; i < n; i++) {
		printf("%s",no[i]);
		
		/*
		printf("%s", temp.c_str());
		for (int j = 0; j < 2 * n - 1; j++) {
			printf("%c", p[i][j]);
		}
		*/

		cout << "\n";
	}
    return 0;
}

