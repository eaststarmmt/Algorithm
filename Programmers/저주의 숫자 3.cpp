#include <string>
#include <vector>
#include<iostream>
using namespace std;

bool check(int x) {
	if (x < 10) return false;
	while (x) {
		if (x % 10 == 3) return true;
		x /= 10;
	}
	return false;
}

int solution(int n) {
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer++;
		while (true) {
			if (answer % 3 == 0) answer++;
			else if (check(answer)) answer++;
			else break;
		}
	}
	return answer;
}