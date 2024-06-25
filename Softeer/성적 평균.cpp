#include<iostream>
#include<cmath>

using namespace std;

int N, K;
int psum[1000004];

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {  // 누적합
		int x;
		cin >> x;
		psum[i] = psum[i - 1] + x;
	}

	cout.precision(2);
	cout << fixed;

	for (int i = 0; i < K; i++) {
		int lo, hi;
		cin >> lo >> hi;
		cout << (double(psum[hi] - psum[lo - 1]) / (hi - lo + 1)) << '\n';
	}

	return 0;
}