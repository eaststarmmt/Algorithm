#include <string>
#include <vector>

using namespace std;
int dp[60001];
int solution(int n) {
	int answer = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {   // n - 1에서 세로 한개 붙이는 경우 + n - 2에서 가로 두개 붙이는 경우 두가지 밖에 없음
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
	}
	answer = dp[n];
	return answer;
}