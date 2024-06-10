#include<iostream>
#include<algorithm>

using namespace std;

int psum[100004];
int N, M, l, r, x;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {	// 누적합
		cin >> x;
		psum[i] = psum[i - 1] + x;
	}	// end of for

	for (int i = 0; i < M; i++) {
		cin >> l >> r;
		cout << psum[r] - psum[l - 1] << '\n';
	}	// end of for

	return 0;
}