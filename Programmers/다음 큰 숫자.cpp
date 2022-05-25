#include <string>
#include <vector>
using namespace std;

int oneCount(int n) {
	int cnt = 0;
	int cmp = 1;    // 비교할 숫자. 왼쪽으로 shift 하면서 1 개수 세기
	for (int i = 0; i < 31; i++) {  // int 범위가 2^32 - 1 이므로 31번 하면 최대임
		if ((cmp & n) != 0) {
			cnt++;
		}
		cmp <<= 1;
	}   // end of for
	return cnt;
}

int solution(int n) {
	int answer = 0;
	int target = oneCount(n);
	for (int i = n + 1; i <= 1000000; i++) {
		if (target == oneCount(i)) {
			answer = i;
			break;
		}
	}
	return answer;
}