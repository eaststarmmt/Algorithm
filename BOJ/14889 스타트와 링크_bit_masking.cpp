#ifdef _MSC_VER
#	include<intrin.h>
#	define __builtin_popcount __popcnt
#endif

#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int N;
int S[24][24];
int res = INF;

int calc(vector<int>& start, vector<int>& link) {
	pair<int, int> score;

	for (int i = 0; i < start.size(); i++) {
		for (int j = 0; j < start.size(); j++) {
			score.first += S[start[i]][start[j]];
			score.second += S[link[i]][link[j]];
		}	// end of for j
	}	// end of for i

	return abs(score.first - score.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> S[i][j];
		}	// end of for j
	}	// end of for i

	for (int i = 1; i < (1 << N); i++) {
		if (__builtin_popcount(i) != N / 2) {	// 반반 나눠지지 않은 경우 무시
			continue;
		}

		vector<int> start;
		vector<int> link;

		for (int j = 1, bit = 1; j <= N; j++, (bit <<= 1)) { // 팀 나누기
			if (i & bit) {
				start.push_back(j);
			}
			else {
				link.push_back(j);
			}
		}	// end of for j

		res = min(res, calc(start, link));
	}	// end of for i
	cout << res << "\n";

	return 0;
}