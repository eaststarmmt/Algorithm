#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int N, sum, x;
int res = -INF;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		sum += x;
		res = max(sum, res);	// 나오는 숫자마다 더하면서 최댓값 갱신

		if (sum < 0) sum = 0;	// 합이 음수면 다음 숫자에 더해도 최대값에서 멀어지기 때문에 다음 지점부터 시작하는게 더 높은 값을 뽑을 수 있음
	}

	cout << res << "\n";
	return 0;
}