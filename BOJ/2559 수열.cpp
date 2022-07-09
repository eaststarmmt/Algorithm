#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int psum[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		psum[i] = psum[i - 1] + x;
	}	// end of for

	int res = -INF;

	for (int i = K; i <= N; i++) {
		res = max(res, psum[i] - psum[i - K]);
	}
	cout << res << "\n";
	return 0;
}