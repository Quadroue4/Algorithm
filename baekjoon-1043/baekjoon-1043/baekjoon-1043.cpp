// baekjoon-1043.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	cin >> trueN; // �ʱ⿡ ����� �˰��ִ� ����� ��. 
	for (int i = 0; i < trueN; i++) {
		int index;
		cin >> index; 
		trueMans[index-1] = true;
	}
	for (int i = 0; i < M; i++) {
		cin >> partyN[i]; //�� ��Ƽ�� �ο����� ����.
		for (int j = 0; j < partyN[i]; j++) {
			cin >> party[i][j];
			party[i][j] = party[i][j] - 1; // ���� 1���� �ֹǷ�, �ε��������� ����Ͽ� 1�� ������.
		}
		for (int j = 0; j < partyN[i]; j++) {
			for (int k = j+1; k < partyN[i]; k++) { //���� ��Ƽ�� �ٸ� ȸ���鳢�� ������ Ʈ�����̺� �÷�����.
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
	while (!judge) { //temp��trueMans�� ���Եɶ����� ����.
		for (int i = 0; i < N; i++) // �ϴ� temp�� trueMans ����ȭ.
			temp[i] = trueMans[i];

		for (int i = 0; i < N; i++) //trueMans ������Ʈ
			if (trueMans[i]) {
				for (int j = 0; j < N; j++)
					if (truetable[i][j])
						trueMans[j] = true;
			}
		//printf("1");
		judge = true; //trueMans �� temp ��
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

