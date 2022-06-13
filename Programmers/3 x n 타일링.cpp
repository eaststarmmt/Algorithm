#include <string>
#include <vector>

using namespace std;
long long dp[5001];
int solution(int n) {
	int answer = 0;
	dp[0] = 1;  // 끝에 두가지 곱하기 위해서
	dp[2] = 3;
	for (int i = 4; i <= n; i += 2) {    // 홀수는 불가능. n - 2에서 2를 만들 수 있는 경우 3가지를 곱하고 위 아래에 끼워넣는 2개를 더함
		dp[i] = (dp[i - 2] * 3) % 1000000007;
		for (int j = i - 4; j >= 0; j -= 2) {    // 위아래에 한줄로 껴지는 경우 계산하기 위함
			dp[i] = (dp[i] + dp[j] * 2) % 1000000007;
		}
	}
	answer = (int)dp[n] % 1000000007;
	return answer;
}