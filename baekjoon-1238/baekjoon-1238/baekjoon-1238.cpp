// baekjoon-1238.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include<iostream>
#include<queue>
using namespace std;


struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int main()
{
	int N, M, X;
	int **path = new int*[1000];
	for (int i = 0; i < 1000; i++)
		path[i] = new int[1000];
	int come[1000]; // All to X cost 
	int turn[1000]; // X to All cost
					
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++)
			path[i][j] = -1; // 0���� �ʱ�ȭ �ϴ°� ������..?
		come[i] = -1; //�湮������ ������ Ȯ���Ҽ� �����Ƿ� -1�� �ϴ°� �Ǿƺ���.
		turn[i] = -1; // //
	}

	cin >> N >> M >> X;
	X--; //�ε����� �����ֱ� ���� 1��
	for (int i = 0; i < M; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		path[start-1][end-1] = cost;
	}
	
	priority_queue<pair<int, int>,vector<pair<int,int>>,cmp> q;
	q.push(make_pair(X, 0));
	while (!q.empty()) {
		pair<int,int> tmp = q.top();
		q.pop();
		if (turn[tmp.first] == -1) {//ť�� ���� ���� ���� ��츸 ó���ϱ� ����
			turn[tmp.first] = tmp.second;

			for (int i = 0; i < N; i++) {
				int target = path[tmp.first][i];

				if (target != -1) { // ���� �ش簪������ ���� �������� �߰�
					int targetCost = tmp.second + target;
					q.push(make_pair(i, targetCost));
				}
			}
		}
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q2; //�̹��� ������ cost ���. ���� ����.
	q2.push(make_pair(X, 0));
	while (!q2.empty()) {
		pair<int, int> tmp = q2.top();
		q2.pop();
		if (come[tmp.first] == -1) {//ť�� ���� ���� ���� ��츸 ó���ϱ� ����
			come[tmp.first] = tmp.second;

			for (int i = 0; i < N; i++) {
				int target = path[i][tmp.first]; //������. i -> tmp.first���� ��.

				if (target != -1) { // ���� �ش簪������ ���� �������� �߰�
					int targetCost = tmp.second + target;
					q2.push(make_pair(i, targetCost));
				}
			}
		}
	}
	int total[1000];
	int max = 0;
	for (int i = 0; i < N; i++) {
		total[i] = come[i] + turn[i];
		if (max < total[i])
			max = total[i];
	}

	cout << max;

	
    return 0;
}

