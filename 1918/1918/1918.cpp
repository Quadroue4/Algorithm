// 1918.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	
	do{ // ��ü�� ���� ( ) ����.
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
	for (i = str.size() - 1; i >= 0; i--) { //+ �� - �� ������ �������, �װ� �������� �¿� ����.
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
	// ���� ���� �ٱ� �������߿��� * / �� �����Ƿ�, ���� ���� * �Ǵ� / �� �������� �� �� ����.
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

