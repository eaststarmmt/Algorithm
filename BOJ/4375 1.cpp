#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	while (cin >> n) {
		int res = 1;
		int cnt = 1;
		while (true) {
			if (res % n == 0) {
				break;
			}
			res = res * 10 + 1;
			res %= n;
			cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}