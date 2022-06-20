#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int getN(int target, int N) {
	int x = 0;
	for (int i = 0; i <= target; i++) {
		x = x * 10 + N;
	}
	return x;
}

int solution(int N, int number) {
	int answer = -1;
	if (N == number) {   // 자기자신이면 1
		return 1;
	}
	unordered_set<int> set[8];
	set[0].insert(N);
	for (int target = 1; target < 8; target++) {    // N의 총 개수 - 1
		for (int i = 0; i < target; i++) {
			for (int j = 0; j < target; j++) {
				if (i + j + 1 != target) continue;   // 0번 인덱스가 1을 가리키므로 i + j에 1을 더해줘야 target과 숫자가 맞음
				for (int x : set[i]) {
					for (int y : set[j]) {
						set[target].insert(x + y);
						if (x > y) {
							set[target].insert(x - y);
						}
						set[target].insert(x * y);
						if (y != 0 && x / y > 0) {    // 분모가 0인경우 터질 수 있으므로 0이 아닐때만 저장
							set[target].insert(x / y);
						}
					}   // end of for x
				}   // end of for y
			}   // end of for j
		}   // end of for i
		set[target].insert(getN(target, N));    // 사칙연산 없이 N으로 이루어진 숫자 저장. ex NNN
		if (set[target].find(number) != set[target].end()) {
			return target + 1;
		}
	}   // end of for target
	return answer;
}