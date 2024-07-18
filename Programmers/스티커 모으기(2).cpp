#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[2][100004];

int go(int x, vector<int>& v) {
	int size = x & 1 ? v.size() : v.size() - 1;
	if (size == 1) return v[0];
	for (int i = 2; i < size; i++) {
		dp[x][i] = max(v[i] + dp[x][i - 2], dp[x][i - 1]);
	}   // end of for

	return dp[x][size - 1];
}

int solution(vector<int> sticker)
{
	int answer = 0;
	// 첫번째 스티커를 쓰는 경우
	dp[0][0] = sticker[0];
	dp[0][1] = sticker[0];
	int res1 = go(0, sticker);

	dp[1][1] = sticker[1];
	int res2 = go(1, sticker);

	answer = max(res1, res2);
	return answer;
}