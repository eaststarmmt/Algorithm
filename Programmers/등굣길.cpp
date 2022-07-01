#include <string>
#include <vector>

using namespace std;

int dp[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {   // n이 세로 m이 가로
	int answer = 0;

	for (int i = 1; i <= n; i++) {  // 1로 다 초기화
		for (int j = 1; j <= m; j++) {
			dp[i][j] = 1;
		}
	}

	for (int i = 0; i < puddles.size(); i++) {
		int r = puddles[i][1];
		int c = puddles[i][0];
		dp[r][c] = 0;   // 물 웅덩이 0으로 저장
		if (r == 1) {
			for (int idx = c; idx <= m; idx++) {    // 1이 나온 시점부터 첫줄 or 첫 열은 다 갈 수 없음
				dp[r][idx] = 0;
			}
		}
		if (c == 1) {
			for (int idx = r; idx <= n; idx++) {
				dp[idx][c] = 0;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			if (dp[i][j] == 0) continue;    // 웅덩이면 무시
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007; // 위까지 가는 경로와 왼쪽까지 가는 경로의 합 

		}
	}
	answer = dp[n][m];
	return answer;
}