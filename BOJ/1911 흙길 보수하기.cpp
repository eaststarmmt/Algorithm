#include <bits/stdc++.h>
using namespace std;

int N, L, res;
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		int from, to;
		cin >> from >> to;
		v.push_back({ from, to });
	}	// end of for 

	sort(v.begin(), v.end());	// 라인 스위핑을 하기 위해 시작점 기준 정렬

	int idx = 0;
	int cnt;
	for (int i = 0; i < v.size(); i++) {
		if (idx >= v[i].second) {	// 겹치는 경우
			continue;
		}
		if (idx >= v[i].first) {		// 널빤지가 걸치는 경우
			cnt = (v[i].second - idx) / L + ((v[i].second - idx) % L == 0 ? 0 : 1);
			idx = idx + L * cnt;	// 어디서 끝났는지 체크
		}
		else {	// 크게 떨어져서 웅덩이 시작점부터 시작하면 되는 경우
			cnt = (v[i].second - v[i].first) / L + ((v[i].second - v[i].first) % L == 0 ? 0 : 1);
			idx = v[i].first + L * cnt;
		}
		res += cnt;
	}	// end of for

	cout << res << "\n";

	return 0;
}