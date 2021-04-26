// 1753.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
struct cmp {
	bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
		return a.first > b.first;
	}
};
*/

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int distance[20001];
	for (int i = 0; i < 20001; i++) {
		distance[i] = -1;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>> q;

	int v, e;
	cin >> v >> e;
	int startV;
	vector<pair<int, int>> arr[20001];
	cin >> startV;
	q.push(make_pair(0, startV));
	for (int i = 0; i < e; i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		arr[v1].push_back(make_pair(v2, w));
	}

	while (!q.empty()) {
		pair<int, int> temp = q.top();
		q.pop();
		int w = temp.first*(-1);
		int v1 = temp.second;
		if (distance[v1] == -1) {
			distance[v1] = w;
			for (int i = 0; i < arr[v1].size(); i++) {
				int first = arr[v1][i].first;
				int second = arr[v1][i].second;
				q.push(make_pair(-1 * (w + second), first));
			}
		}
	}


	for (int i = 1; i <= v; i++) {
		int p = distance[i];
		if (p != -1)
			cout << p << "\n";
		else
			cout << "INF\n";
	}
    return 0;
}

