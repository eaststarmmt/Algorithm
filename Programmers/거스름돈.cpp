#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dp[100004];

int solution(int n, vector<int> money) {
	int answer = 0;
	dp[0] = 1;

	for (int x : money) {
		for (int i = x; i <= n; i++) {
			dp[i] += dp[i - x] % 1000000007;
		}
	}   // end of money

	answer = dp[n];
	return answer;
}