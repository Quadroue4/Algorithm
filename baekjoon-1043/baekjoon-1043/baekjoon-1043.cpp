// baekjoon-1043.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int N, M;
	int trueN;
	bool trueMans[50];
	int party[50][50];
	int partyN[50];
	bool truetable[50][50];
	for (int i = 0; i < 50; i++) {
		trueMans[i] = false;
		for (int j = 0; j < 50; j++)
			truetable[i][j] = false;
	}
	cin >> N >> M;
	cin >> trueN; // 초기에 사실을 알고있는 사람의 수. 
	for (int i = 0; i < trueN; i++) {
		int index;
		cin >> index; 
		trueMans[index-1] = true;
	}
	for (int i = 0; i < M; i++) {
		cin >> partyN[i]; //각 파티의 인원수를 저장.
		for (int j = 0; j < partyN[i]; j++) {
			cin >> party[i][j];
			party[i][j] = party[i][j] - 1; // 값을 1부터 주므로, 인덱스범위를 고려하여 1씩 빼주자.
		}
		for (int j = 0; j < partyN[i]; j++) {
			for (int k = j+1; k < partyN[i]; k++) { //같은 파티의 다른 회원들끼리 서로의 트루테이블에 올려주자.
					truetable[party[i][j]][party[i][k]] = true;
					truetable[party[i][k]][party[i][j]] = true;
			}
		}
	}
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", truetable[i][j]);
		}
		printf("\n");
	}
	*/
	bool temp[50];

	bool judge = false;
	while (!judge) { //temp와trueMans가 같게될때까지 돌림.
		for (int i = 0; i < N; i++) // 일단 temp와 trueMans 동기화.
			temp[i] = trueMans[i];

		for (int i = 0; i < N; i++) //trueMans 업데이트
			if (trueMans[i]) {
				for (int j = 0; j < N; j++)
					if (truetable[i][j])
						trueMans[j] = true;
			}
		//printf("1");
		judge = true; //trueMans 와 temp 비교
		for (int i = 0; i < N; i++)
			if (temp[i] != trueMans[i]) {
				temp[i] = trueMans[i];
				judge = false;
			}
	}
	//printf("1");
	int trueCount = 0;
	int truer[50];
	for (int i = 0; i < N; i++)
		if (trueMans[i])
			truer[trueCount++] = i;

	int count = M;
	for (int i = 0; i < M; i++) {
		bool sex = true;
		for (int j = 0; j < partyN[i]; j++) {
			for (int k = 0; k < trueCount; k++) {
				if (party[i][j] == truer[k])
					sex = false;
			}
		}
		if (!sex)
			count--;
	}
	printf("%d", count);


    return 0;
}

