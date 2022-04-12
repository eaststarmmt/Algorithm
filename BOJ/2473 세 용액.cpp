#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int sol[5000];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &sol[i]);
	}	// end of input

	sort(sol, sol + N);
	int ans[3] = { 0 };	// 정답 출력할 배열
	ll minVal = 50000000000;	// 최소값 기록
	for (int i = 0; i < N - 2; i++) {
		int start = i;
		int left = i + 1;
		int right = N - 1;
		while (left < right) {	// 투포인터 개념
			ll sum = (ll)sol[start] + sol[left] + sol[right];	// 캐스팅 안하면 int라 제대로 못 읽음
			if (minVal > abs(sum)) {			// 절대값 더 작으면 갱신
				ans[0] = sol[start];
				ans[1] = sol[left];
				ans[2] = sol[right];
				minVal = abs(sum);
			}
			if (sum > 0) 	// 양수인 경우 right를 앞으로 땡겨서 숫자 줄여줌
				right--;
			else if (sum < 0) // 음수인 경우 left를 뒤로 밀어서 숫자 늘려줌
				left++;
			else {		// 0 이면 어차피 하나만 출력하면 되므로 바로 종료
				printf("%d %d %d\n", ans[0], ans[1], ans[2]);
				return 0;
			}
		}
	}
	printf("%d %d %d\n", ans[0], ans[1], ans[2]);
}