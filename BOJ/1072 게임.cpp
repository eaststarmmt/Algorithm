#include <iostream>
using namespace std;

long long X, Y, Z;
long long res = -1;		// Z가 변하지 않는다면 res도 바뀌지 않음

bool check(long long mid) {
	long long avg = (long long)100 * (Y + mid) / (X + mid);
	return avg > Z;		// mid를 더했을 때 Z 보다 커져야 됨
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> X >> Y;
	Z = (long long)100 * Y / X;	// 100을 먼저 안곱하면 0이 됨

	long long lo = 1;
	long long hi = 1e9;		// X가 10억이 나왔을 때 왠만한 숫자로는 변하지 않음

	while (lo <= hi) {
		long long mid = (lo + hi) / 2;

		if (check(mid)) {
			hi = mid - 1;	// 최솟값 문제이기 때문에 값을 줄이는 방향으로
			res = mid;
		}
		else {
			lo = mid + 1;
		}
	}	// end of while

	cout << res << "\n";

	return 0;
}