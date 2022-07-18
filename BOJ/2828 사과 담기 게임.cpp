#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	int j;
	cin >> j;
	int start = 1;
	int end = M;
	int res = 0;
	for (int i = 0; i < j; i++) {
		int x;
		cin >> x;
		if (x < start) {
			int dif = start - x;
			res += dif;
			start = x;
			end -= dif;
		}
		else if (x > end) {
			int dif = x - end;
			res += dif;
			end = x;
			start += dif;
		}
	}	// end of for

	cout << res << "\n";

	return 0;
}