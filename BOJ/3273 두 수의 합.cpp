#include <iostream>
#include <algorithm>
using namespace std;

int num[100004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}

	sort(num, num + N + 1);
	int x;
	cin >> x;

	int start = 1;
	int end = N;
	int res = 0;
	while (start < end) {
		int sum = num[start] + num[end];
		if (sum == x) {
			res++;
			start++;
			end--;
		}
		else if (sum < x) {
			start++;
		}
		else if (sum > x) {
			end--;
		}
	}
	cout << res << "\n";
	return 0;
}