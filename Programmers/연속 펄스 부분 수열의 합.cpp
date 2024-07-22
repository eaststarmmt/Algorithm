#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long seq[2][500004], dp[2][500004];

void set_seq(int x, vector<int>& v) {
	int flag = x ? 1 : -1;

	for (int i = 0; i < v.size(); i++, flag *= -1) {
		seq[x][i] = v[i] * flag;

	}

}

long long solution(vector<int> sequence) {
	long long answer = 0;
	set_seq(0, sequence);
	set_seq(1, sequence);

	dp[0][0] = seq[0][0];
	dp[1][0] = seq[1][0];
	answer = max(dp[0][0], dp[1][0]);

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < sequence.size(); j++) {
			dp[i][j] = max(dp[i][j - 1] + seq[i][j], seq[i][j]);
			answer = max(dp[i][j], answer);
		}   // end of for j
	}   // end of for i
	return answer;
}