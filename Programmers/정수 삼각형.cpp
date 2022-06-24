#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp[500][500];

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	dp[0][0] = triangle[0][0];
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = 0; j < triangle[i].size(); j++) {
			if (j == 0) {    // 왼쪽은 무조건 위에서만 내려옴
				dp[i][j] = triangle[i][j] + dp[i - 1][j];
			}
			else if (i == j) { // 오른쪽은 무조건 위에서만 내려옴
				dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
			}
			else {    // 그 외 나머지
				dp[i][j] = triangle[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
			}
		}   // end of for j
	}   // end of for i

	for (int i = 0; i < triangle.size(); i++) {
		answer = dp[triangle.size() - 1][i] > answer ? dp[triangle.size() - 1][i] : answer;
	}

	return answer;
}