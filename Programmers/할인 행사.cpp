#include <bits/stdc++.h>

using namespace std;

map<string, int> m, want_m;
int answer;

void check() {
	// want가 원하는 수량과 현재 보고 있는 10의 수량 비교
	for (map<string, int>::iterator i = want_m.begin(); i != want_m.end(); i++) {
		if (m[i->first] != i->second) return;
	}
	answer++;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	// 필요한 조건이 저장
	for (int i = 0; i < want.size(); i++) {
		want_m[want[i]] = number[i];
	}   // end of for
	// 1 ~ 10일 할인 상품 조회
	for (int i = 0; i < 10; i++) {
		m[discount[i]]++;
	}

	check();
	// 10일전 할인 상품 감소 현재 할인 상품 증가
	for (int i = 10; i < discount.size(); i++) {
		m[discount[i - 10]]--;
		m[discount[i]]++;
		check();
	}

	return answer;
}