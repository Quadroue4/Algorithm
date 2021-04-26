// baekjoon-1504.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
// �ʼ��� �������ϴ� �� �ΰ��� v1,v2��� �Ѵٸ�,
//���ͽ�Ʈ�� 1�������� �ѹ�, N�������� �ѹ�, v1,v2���� �� �ѹ� �� 4�� �ϸ� �ɰ�.
bool func(int idx,int* cost) {
	for (int i = 0; i < 800; i++)
		cost[i] = -1;
	priority_queue < pair<int, int>, vector<pair<int, int>>, cmp> q;
	q.push(make_pair(idx,0));
	while (!q.empty()) {
		pair<int, int> tmp = q.top();
		q.pop();
		if (cost[tmp.first] == -1) {//������Ʈ�� �������� �����̶��
			cost[tmp.first] = tmp.second;
			//cout << "idx = "<<idx<<" " << tmp.first << " " << tmp.second;
			for (int i = 0; i < 800; i++) {
				if (arr[tmp.first][i] != -1) // ��, ��ΰ� �����Ѵٸ�,
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
		arr[from-1][to-1] = cost; //idx�� 0���� �����ϰ� ����� ���� 1�� ����.
		arr[to - 1][from - 1] = cost;
	}
	int v1, v2;
	cin >> v1 >> v2;
	v1--; v2--; // �� �ּ��� ��������.
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

