#include <string>
#include <vector>

using namespace std;

int square[1001];

int solution(int left, int right) {
	int answer = 0;
	for (int i = 1; i * i <= 1000; i++) {
		square[i * i] = true;
	}
	// 제곱수는 약수가 홀수. 제곱수가 아니면 짝수
	for (int i = left; i <= right; i++) {
		square[i] ? answer -= i : answer += i;
	}   // end of for

	return answer;
}