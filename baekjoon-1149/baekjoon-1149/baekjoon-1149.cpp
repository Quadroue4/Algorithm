// baekjoon-1149.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int N=0;
	scanf_s("%d", &N);
	int arr[1000][3];
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			int cost = 0;
			scanf_s("%d", &cost);
			arr[i][j] = cost;
		}
		count++;
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < 3; j++) {
			int min = 9999999;
			for (int k = 0; k < 3; k++) {
				if (j != k) {
					if (arr[i][k] < min)
						min = arr[i][k];
				}
			}
			arr[i+1][j] += min;
		}
	}
	int min = 99999999;
	for (int i = 0; i < 3; i++) {
		if (arr[N - 1][i] < min)
			min = arr[N - 1][i];
	}

	return min;
}

