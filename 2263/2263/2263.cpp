// 2263.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
		return a.first.first > b.first.first;
	}
};

int main()
{

	int n;
	vector<int> inorder;
	vector<int> postorder;
	string temp = "";

	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		inorder.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		postorder.push_back(temp);
	}

	vector<int> preorder;

	priority_queue<pair<pair<int, int>, pair<int, int>>,vector<pair<pair<int, int>, pair<int, int>>>,cmp> q;
	q.push(make_pair(make_pair(0, n - 1),make_pair(0,n-1)));
	while (!q.empty()) {
		auto temp = q.top();
		q.pop();
		auto intemp = temp.first;
		auto potemp = temp.second;

		if (intemp.second - intemp.first < 0)
			continue;

		else if (intemp.second - intemp.first == 0) {
			preorder.push_back(inorder[intemp.first]);
			continue;
		}
		int target = postorder[potemp.second];
		preorder.push_back(target);
		int idx=0;
		for (int i = intemp.first; i <= intemp.second; i++) {
			if (inorder[i] == target) {
				idx = i;
				break;
			}
		}
		pair<int, int> inslice1 = make_pair(intemp.first, idx - 1);
		pair<int, int> inslice2 = make_pair(idx +1,intemp.second);
		pair<int, int> poslice1 = make_pair(potemp.first, potemp.first + (idx - 1 - intemp.first));
		pair<int, int> poslice2 = make_pair(potemp.first + (idx - 1 - intemp.first)+1, potemp.second - 1);

		q.push(make_pair(inslice1, poslice1));
		q.push(make_pair(inslice2, poslice2));
	}
	for (int i = 0; i < n; i++)
		cout << preorder[i] << " ";

    return 0;
}

