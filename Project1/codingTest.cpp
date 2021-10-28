#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define endl "\n"
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<pair<int, string>> input;
	for (int i = 0; i < N; i++) {
		int x;
		string s;
		cin >> x >> s;
		input.push_back({ x, s });
	}
	sort(input.begin(), input.end(), cmp);
	for (int i = 0; i < N; i++) {
		cout << input[i].first << " " << input[i].second << endl;
	}
}