#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int test = 1; test <= T; test++) {
		int x;
		cin >> x;
		int cnt2 = 0;
		int cnt5 = 0;
		for (int i = 2; i <= x; i *= 2) {	// 2의 지수 단위로 늘려서 더하는 방식. 4는 2에서 한번 계산 되었으므로 몫 만큼만 더해주면 됨
			cnt2 += x / i;
		}

		for (int i = 5; i <= x; i *= 5) {
			cnt5 += x / i;
		}

		cout << min(cnt2, cnt5) << "\n";
	}
	return 0;
}