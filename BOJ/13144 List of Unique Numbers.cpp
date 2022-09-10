#include <iostream>
using namespace std;

long long visited[100001];
long long seq[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> seq[i];
	}	// end of for i

	long long res = 0;
	long long left = 0, right = 0;

	while (right < N) {
		if (!visited[seq[right]]) {	// 지금 보고 있는 범위 내에 right가 없는 경우
			visited[seq[right]]++;
			right++;
		}
		else {	// 중복된 숫자가 있으면 왼쪽에 숫자 빼고 right까지 하나씩 카운팅
			res += (long long)right - left;
			visited[seq[left]]--;
			left++;
		}
	}	// end of while

	res += (right - left) * (right - left + 1) / 2;
	cout << res << "\n";

	return 0;
}