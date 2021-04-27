// 1932.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>>
#include <algorithm>

using namespace std;

int arr[500][500];
int result[500][500];


int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
			result[i][j] = -1;
		}
	}
	result[0][0] = arr[0][0];

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j <= i; j++) {
			result[i + 1][j] = max(result[i + 1][j], result[i][j] + arr[i + 1][j]);
			result[i + 1][j + 1] = max(result[i + 1][j + 1], result[i][j] + arr[i + 1][j + 1]);
		}
	}
/*
	for(int i=0;i<N;i++)
		for (int j = 0; j <= i; j++) {
			cout << result[i][j];
		}
	*/
	int max1 = 0;

	for (int i = 0; i < N; i++)
		if (result[N - 1][i] > max1)
			max1 = result[N - 1][i];

	cout << max1;
    return 0;
}

