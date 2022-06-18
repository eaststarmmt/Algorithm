#include <string>
#include <vector>
#include <cmath>
using namespace std;

int col[12];
int N;
int answer;

bool check(int r) {     // 같은 열에 있거나 대각 관계에 있는지 체크
	for (int i = 0; i < r; i++) {
		if ((r - i) == abs(col[r] - col[i]) || (col[i] == col[r])) { // r-i 와 abs(col[r] - col[i]) 가 같으면 대각관계
			return false;
		}
	}
	return true;
}

void comb(int r) {
	if (!check(r - 1)) {     // r -1 까지 조건에 맞는지 확인
		return;
	}
	if (r == N) {    // N개 만큼 퀸을 배치했으면 카운팅
		answer++;
		return;
	}

	for (int c = 0; c < N; c++) {
		col[r] = c;
		comb(r + 1);
	}
}

int solution(int n) {
	answer = 0;
	N = n;
	comb(0);
	return answer;
}