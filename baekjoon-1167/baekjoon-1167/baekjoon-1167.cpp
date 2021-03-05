// baekjoon-1167.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> tree[100000];
pair<int,int> bfs(int idx) {
	int arr[100000];
	queue<int> q;

	for (int i = 0; i < 100000; i++)
		arr[i] = -1;

	q.push(idx);
	arr[idx] = 0; // ����-���� �Ÿ��� 0�̴ϱ�
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (int i = 0; i<tree[temp].size(); i++) {
			if (arr[tree[temp][i].first] == -1) {// ���� ���ξ��� �ε������� ���� �����ϴ� ���̶��,
				arr[tree[temp][i].first] = arr[temp] + tree[temp][i].second; //Ǫ���ϸ鼭 �ش簪������ ���� ����.
				q.push(tree[temp][i].first);
			}
		}

	}
	int idx1 = -1;
	int max = 0;
	for (int i = 0; i < 100000; i++){
		if (max < arr[i]) {
			max = arr[i];
			idx1 = i;
		}
	}
	return make_pair(idx1, max);
}

int main()
{
	int N;
	int V;
	int temp1, temp2;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> V; // ���� �����.
		do {
			cin >> temp1;
			if (temp1 != -1) {
				cin >> temp2;
				temp1--;//idx�� �����Ϸ��� 1�� ���°� ����.
				tree[V-1].push_back(make_pair(temp1, temp2));
			}
		} while (temp1 != -1);
	}
	pair<int, int> hi = bfs(0);
	pair<int, int> bye = bfs(hi.first);
	//cout << hi.first << hi.second << bye.first << bye.second;
	cout<<(bye.second);

	return 0;
}

