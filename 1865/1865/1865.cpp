// 1865.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int arr[501][501];
using namespace std;

#define INFINITE INT_MAX;

void Reset() {
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			if (i != j)
				arr[i][j] = INFINITE;
		}
		arr[i][i] = 0;
	}
}

bool Infinite(int a) {
	return a >= INFINITE;
}
bool floyd_washal_negative_cognitive(int V) {
	for (int k = 1; k <= V; k++) { // loop for each vertex
		for (int start = 1; start <= V; start++) {
			for (int end = 1; end <= V; end++) {
				if (k != start && k != end) { //start != end 를 넣으면 negative cycle 발견하기 힘들거같음ㅇㅇ
					if(!Infinite(arr[start][k]) && !Infinite(arr[k][end]))
						arr[start][end] = min(arr[start][end], arr[start][k] + arr[k][end]);
				}
			}
		}
	}
	bool judge = false;
	for (int i = 1; i <= V; i++)
		if (arr[i][i] < 0)
			judge = true;
	if (judge)
		cout << "YES\n";
	else
		cout << "NO\n";
	return true;
}


int main()
{
	int TestCase;
	cin >> TestCase;

	for (int i = 0; i < TestCase; i++) {
		Reset();
		int N, M, W;
		int S, E, T;
		cin >> N >> M >> W;
		for (int j = 0; j < M; j++) {
			cin >> S >> E >> T;
			arr[S][E] = min(arr[S][E], T);
			arr[E][S] = min(arr[S][E], T);
		}
		for (int j = 0; j < W; j++) {
			cin >> S >> E >> T;
			arr[S][E] = min(arr[S][E], (-1)*T);
		}
		floyd_washal_negative_cognitive(N);
	}
    return 0;
}

