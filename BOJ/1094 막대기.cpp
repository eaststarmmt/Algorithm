#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int res = 0;
	while (N > 0) {		// 23 = 10111. 오른쪽으로 shift 하면서 1과의 & 연산으로 1의 개수 카운팅
		if (N & 1) {
			res++;
		}
		N >>= 1;
	}	// end of while

	cout << res << "\n";
	return 0;
}