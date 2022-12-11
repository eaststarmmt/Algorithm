#include <bits/stdc++.h>

using namespace std;

map<int, int> m;
int _left[1000004];
int _right[1000004];

int solution(vector<int> topping) {
	int answer = 0;
	int size = topping.size();

	// 0 ~ size - 2 까지 토핑 가지 수
	for (int i = 0; i < size - 1; i++) {
		m[topping[i]]++;
		_left[i] = m.size();
	}   // end of for left

	m.clear();

	// size - 1 ~ 0 까지 토핑 가지 수
	for (int i = size - 1; i >= 1; i--) {
		m[topping[i]]++;
		_right[i] = m.size();
	}

	for (int i = 0; i < size - 1; i++) {
		if (_left[i] == _right[i + 1]) answer++;
	}

	return answer;
}