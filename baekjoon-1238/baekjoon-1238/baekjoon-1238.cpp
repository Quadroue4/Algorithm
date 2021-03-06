// baekjoon-1238.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
			path[i][j] = -1; // 0으로 초기화 하는게 맞을까..?
		come[i] = -1; //방문한적이 있음을 확인할수 있으므로 -1로 하는게 옳아보임.
		turn[i] = -1; // //
	}

	cin >> N >> M >> X;
	X--; //인덱스값 맞춰주기 위해 1뺌
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
		if (turn[tmp.first] == -1) {//큐에 들어온 적이 없는 경우만 처리하기 위해
			turn[tmp.first] = tmp.second;

			for (int i = 0; i < N; i++) {
				int target = path[tmp.first][i];

				if (target != -1) { // 만약 해당값으로의 길이 있을때만 추가
					int targetCost = tmp.second + target;
					q.push(make_pair(i, targetCost));
				}
			}
		}
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q2; //이번엔 역방향 cost 계산. 로직 동일.
	q2.push(make_pair(X, 0));
	while (!q2.empty()) {
		pair<int, int> tmp = q2.top();
		q2.pop();
		if (come[tmp.first] == -1) {//큐에 들어온 적이 없는 경우만 처리하기 위해
			come[tmp.first] = tmp.second;

			for (int i = 0; i < N; i++) {
				int target = path[i][tmp.first]; //역방향. i -> tmp.first로의 길.

				if (target != -1) { // 만약 해당값으로의 길이 있을때만 추가
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

