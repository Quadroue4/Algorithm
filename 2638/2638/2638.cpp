// 2638.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int arr[100][100];
int n, m;
vector<pair<int, int>> outs;
vector<pair<int, int>> cheese;

bool judge;
void check_out() {
	do {
		bool out = false;
		queue<pair<int, int>> q;
		vector<pair<int, int>> v;
		judge = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0) {
					q.push(make_pair(i, j));
					judge = true;
					break;
				}
			}
		}
		while (!q.empty()) {
			auto temp = q.front();
			q.pop();
			int h, w;
			h = temp.first;
			w = temp.second;
			if (h == -1 || h == n || w == -1 || w == m || arr[h][w] == 3) {
				out = true;
				continue;
			}

			if (h >= 0 && h < n && w >= 0 && w < m && (arr[h][w] == 0 || arr[h][w] == 2)) {
				arr[h][w] = 4;
				/*
				else { //내부 공기를 만났다 == 내부에 외부 공기가 유입됐다.
					arr[h][w] = 3;
				}
				*/
				v.push_back(make_pair(h, w));
				q.push(make_pair(h + 1, w));
				q.push(make_pair(h, w - 1));
				q.push(make_pair(h - 1, w));
				q.push(make_pair(h, w + 1));
				if (h == 0 || h == n - 1 || w == 0 || w == m - 1 || arr[h][w] == 3)
					out = true;
			}
		}
		if (out) {
			outs.insert(outs.end(), v.begin(), v.end());
			for (int i = 0; i < v.size(); i++)
				arr[v[i].first][v[i].second] = 3;
		}
		else {
			for (int i = 0; i < v.size(); i++)
				arr[v[i].first][v[i].second] = 2;
		}
	} while (judge);
}
int check4(int h, int w) {
	int count = 0;
	if (h - 1 >= 0)
		if (arr[h - 1][w] == 3)
			count++;

	if (w + 1 < m)
		if (arr[h][w + 1] == 3)
			count++;

	if (h + 1 < n)
		if (arr[h + 1][w] == 3)
			count++;
	if (0 <= w - 1)
		if (arr[h][w - 1] == 3)
			count++;

	return count;
}
int main()
{
	cin >> n >> m;
	outs.reserve(10000);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				cheese.push_back(make_pair(i, j));
			}
		}
	}
	cout << "\n";
	int time = 0;

	cout << "\n";
	while (cheese.size() != 0) {
		check_out();
		
		vector < pair<int, int> > newcheese;
		vector <pair<int, int>> rotten;
		for (int i = 0; i < cheese.size(); i++) {
			int h = cheese[i].first;
			int w = cheese[i].second;
			int count = check4(h, w);
			if (count < 2)
				newcheese.push_back(make_pair(h, w));
			else {
				rotten.push_back(make_pair(h, w));
			}
		}
		for (int i = 0; i < rotten.size(); i++)
			arr[rotten[i].first][rotten[i].second] = 0;

		cheese = newcheese;
		time++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}

	cout << time;
    return 0;
}

