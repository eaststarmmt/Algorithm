#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int M;
	cin >> M;
	vector<int> input;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		input.push_back(x);
	}

	sort(input.begin(), input.end());

	int start = 0;
	int end = input.size() - 1;
	int res = 0;
	while (start < end) {
		int sum = input[start] + input[end];
		if (sum < M) {
			start++;
		}
		else if (sum > M) {
			end--;
		}
		else {
			start++;
			end--;
			res++;
		}
	}	// end of while

	cout << res << "\n";
}