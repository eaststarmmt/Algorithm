#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	else return a.size() < b.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<string> vec;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < n; i++) {
		if ((i > 0) && (vec[i] == vec[i - 1])) continue;
		cout << vec[i] << "\n";
	}
}