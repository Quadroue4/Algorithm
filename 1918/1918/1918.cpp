// 1918.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void left_right_opreator(string &str, string &left, string &right, char &oper) {
	int count = 0;
	int i;
	bool judge = false;
	
	do{ // 전체를 덮는 ( ) 제거.
		judge = false;
		for (i = 0; i < str.size(); i++) {
			if (str[i] == '(')
				count++;
			else if (str[i] == ')')
				count--;
			if (count == 0) {
				if (str[0] == '(' && i == str.size() - 1) {
					judge = true;
				}
				break;
			}
		}
		if (judge) {
			str = str.substr(1, str.size() - 2);
		}
	} while (judge);
	
	count = 0;
	string tempLeft, tempRight;
	char tempOper;
	bool tempJudge = false;
	for (i = str.size() - 1; i >= 0; i--) { //+ 나 - 로 연산이 있을경우, 그걸 기준으로 좌우 나눔.
		if (str[i] == '(')
			count++;
		else if (str[i] == ')')
			count--;

		if (!tempJudge && count == 0 && (str[i] == '+' || str[i] == '-')) {
			tempOper = str[i];
			tempJudge = true;
		}
		else if (!tempJudge) {
			tempRight += str[i];
		}
		else if (tempJudge) {
			tempLeft += str[i];
		}

	}

	if (tempJudge) {
		reverse(tempLeft.begin(), tempLeft.end());
		left = tempLeft;
		reverse(tempRight.begin(), tempRight.end());
		right = tempRight;
		oper = tempOper;
		return;
	}

	count = 0;
	tempLeft = "";
	tempRight = "";
	tempJudge = false;
	// 이제 가장 바깥 연산자중에는 * / 만 남으므로, 가장 뒤의 * 또는 / 를 기준으로 좌 우 나눔.
	for (i = str.size() - 1; i >= 0; i--) {
		if (str[i] == '(')
			count++;
		else if (str[i] == ')')
			count--;

		if (!tempJudge && count == 0 && (str[i] == '*' || str[i] == '/')) {
			tempOper = str[i];
			tempJudge = true;
		}
		else if (!tempJudge) {
			tempRight += str[i];
		}
		else if (tempJudge) {
			tempLeft += str[i];
		}
	}
	if (tempJudge) {
		reverse(tempLeft.begin(), tempLeft.end());
		left = tempLeft;
		reverse(tempRight.begin(), tempRight.end());
		right = tempRight;
		oper = tempOper;
		return;
	}
}

void postfix(string str) {
	if (str.size() == 1) {
		cout << str[0];
		return;
	}

	string left, right;
	char oper = 'x';
	left_right_opreator(str, left, right, oper);
	postfix(left);
	postfix(right);
	cout << oper;
}
int main()
{
	string str;
	cin >> str;

	postfix(str);
    return 0;
}

