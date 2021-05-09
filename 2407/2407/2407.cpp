// 2407.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> arr[101][101];
vector<int> numvec[101];

vector<int> calculate(vector<int>& a, vector<int>& b) {
	int rest = 0;
	int mini = min(a.size(), b.size());

	int sum = 0;
	vector<int> ans1;
	//cout << a.size() << " " << b.size() << "\n";
	for (int i = 0; i < mini; i++) {
		sum = a[i] + b[i] + rest;
		rest = sum / 10;
		ans1.push_back(sum % 10);
	}
	if (rest != 0 && a.size() == b.size())
		ans1.push_back(1);

	for (int i = mini; i < a.size(); i++) {
		sum = a[i] + rest;
		rest = sum / 10;
		ans1.push_back(sum % 10);
	}
	for (int i = mini; i < b.size(); i++) {
		sum = b[i] + rest;
		rest = sum / 10;
		ans1.push_back(sum % 10);
	}
	if (a.size() != b.size() && rest != 0)
		ans1.push_back(1);
	return ans1;
}

vector<int> dfs(int n, int m) {
	if (m == 1)
		return numvec[n];
	else if (n == m)
		return numvec[1];
	else if (!arr[n][m].empty())
		return arr[n][m];
	else {
		vector<int> a = dfs(n - 1, m);
		vector<int> b = dfs(n - 1, m - 1);

		arr[n][m] = calculate(a, b);
		return arr[n][m];
	}
}

int main()
{
	vector<int> a, b, c;
	a.push_back(9);
	a.push_back(9);
	a.push_back(9);
	a.push_back(9);
	a.push_back(9);
	b.push_back(1);
	b.push_back(1);
	b.push_back(1);
	b.push_back(1);
	b.push_back(1);
	c = calculate(a, b);
	for (int i = 0; i < c.size(); i++)
		cout << c[c.size() - 1 - i];
	int n, m;
	cin >> n >> m;

	vector<int> temp;

	temp.push_back(0);
	numvec[0] = temp;
	for (int i = 1; i <= 100; i++) {
		int tempnum = i;
		while (tempnum != 0) {
			numvec[i].push_back(tempnum % 10);
			tempnum = tempnum/10;
		}
	}
	vector<int> ans;
	ans = dfs(n, m);

	for (int i = 0; i < ans.size(); i++)
		cout << ans[ans.size() - 1 - i];

    return 0;
}

