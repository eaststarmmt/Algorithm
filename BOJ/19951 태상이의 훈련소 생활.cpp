#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int a[100004], psum[100004];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}	// end of for

	for (int i = 0; i < M; i++) {
		int lo, hi, H;
		cin >> lo >> hi >> H;
		// 누적합의 시작과 끝 위치를 저장. 끝점에 음수로 넣었기 때문에 hi + 1번째부터는 0이 됨
		psum[lo] += H;
		psum[hi + 1] -= H;	
	}	// end of for

	for (int i = 1; i <= N; i++) {
		psum[i] += psum[i - 1];		// 누적합 저장
	}	// end of for

	for (int i = 1; i <= N; i++) {
		a[i] += psum[i];
	}	// end of for

	for (int i = 1; i <= N; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';

	return 0;
}