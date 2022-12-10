#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	return a.second > b.second;
}

map<int, int> m;

int solution(int k, vector<int> tangerine) {
	int answer = 0;

	for (int x : tangerine) {
		m[x]++;
	}   // end of for

	vector<pair<int, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);

	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (cnt >= k) break;
		cnt += v[i].second;
		answer++;
	}

	return answer;
}