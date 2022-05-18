#include <iostream>
using namespace std;

int solution(int n)
{
	int ans = 0;
	// 돌아온 길을 반대로 계산
	while (n > 0) {
		if (n % 2 == 0) {    // 짝수면 순간이동으로 왔다는 의미
			n >>= 1;
		}
		else {    // 홀수면 점프 한 칸
			n--;
			ans++;
		}
	}
	return ans;
}