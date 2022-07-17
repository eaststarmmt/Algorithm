#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<int, int> seq_map;
bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) {
		return seq_map[a.first] < seq_map[b.first];
	}

	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, C;
	cin >> N >> C;
	map<int, int> map;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		map[x]++;

		if (seq_map[x] == 0) {
			seq_map[x] = i + 1;
		}
	}	// end of for
	vector<pair<int, int>> seq(map.begin(), map.end());
	sort(seq.begin(), seq.end(), cmp);
	for (pair<int, int> x : seq) {
		for (int i = 0; i < x.second; i++) {
			cout << x.first << ' ';
		}
	}

	return 0;
}