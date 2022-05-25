#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100000][4];

int solution(vector<vector<int> > land)
{
	int answer = 0;

	for (int i = 0; i < land.size(); i++) {
		dp[i][0] = land[i][0] + max(dp[i - 1][1], max(dp[i - 1][2], dp[i - 1][3]));
		dp[i][1] = land[i][1] + max(dp[i - 1][0], max(dp[i - 1][2], dp[i - 1][3]));
		dp[i][2] = land[i][2] + max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][3]));
		dp[i][3] = land[i][3] + max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
	}   // end of for

	// 마지막 행에서 최대값 고르기
	answer = max(dp[land.size() - 1][0], max(dp[land.size() - 1][1], max(dp[land.size() - 1][2], dp[land.size() - 1][3])));

	return answer;
}