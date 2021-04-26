// baekjoon-1504.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <queue>

int arr[800][800];
using namespace std;
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};
// 필수로 지나야하는 점 두개를 v1,v2라고 한다면,
//다익스트라를 1번점에서 한번, N번점에서 한번, v1,v2에서 각 한번 총 4번 하면 될것.
bool func(int idx,int* cost) {
	for (int i = 0; i < 800; i++)
		cost[i] = -1;
	priority_queue < pair<int, int>, vector<pair<int, int>>, cmp> q;
	q.push(make_pair(idx,0));
	while (!q.empty()) {
		pair<int, int> tmp = q.top();
		q.pop();
		if (cost[tmp.first] == -1) {//업데이트가 되지않은 새삥이라면
			cost[tmp.first] = tmp.second;
			//cout << "idx = "<<idx<<" " << tmp.first << " " << tmp.second;
			for (int i = 0; i < 800; i++) {
				if (arr[tmp.first][i] != -1) // 즉, 경로가 존재한다면,
					q.push(make_pair(i, tmp.second + arr[tmp.first][i]));
			}
		}

	}
	return false;
}
int main()
{
	for (int i = 0; i < 800; i++)
		for (int j = 0; j < 800; j++)
			arr[i][j] = -1;
	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from-1][to-1] = cost; //idx는 0부터 시작하게 만들기 위해 1씩 빼줌.
		arr[to - 1][from - 1] = cost;
	}
	int v1, v2;
	cin >> v1 >> v2;
	v1--; v2--; // 위 주석과 동일이유.
	int cost1[800];
	int cost2[800];
	int cost3[800];
	func(0,cost1);
	func(V - 1,cost2);
	func(v1,cost3);
	//int* l4 = func(v2 - 1);
	int ans1 = -1;
	int ans2 = -1;
	if(cost1[v1] != -1 && cost2[v2] !=-1 && cost3[v2] != -1)
		ans1 = cost1[v1] + cost2[v2] + cost3[v2];// 1->v1->v2->V
	if (cost1[v2] != -1 && cost2[v1] != -1 && cost3[v2] != -1)
		ans2 = cost1[v2] + cost2[v1] + cost3[v2];// 1->v2->v1->V

	if (ans1 > ans2)
		ans1 = ans2;
	cout << ans1;
	return 0;
}

