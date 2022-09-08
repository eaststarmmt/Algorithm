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
	vector<pair<int, int>> cow(N);
	for (int i = 0; i < N; i++) {
		cin >> cow[i].first >> cow[i].second;
	}	// end of for

	sort(cow.begin(), cow.end());
	int res = cow[0].first;

	for (int i = 0; i < N; i++) {
		res = max(cow[i].first, res);	// 현재 시간이 도착 시간보다 늦으면 그대로 사용하고 빠르면 도착시간으로 놓고 계산
		res += cow[i].second;
	}

	cout << res << "\n";
	return 0;
}