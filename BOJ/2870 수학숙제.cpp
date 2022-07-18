#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
using namespace std;

vector<string> res;		// 범위가 너무 커서 longlong으로도 안됨

bool cmp(string& a, string& b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

void save_res(string s) {
	if (s.size() == 0) {
		return;
	}
	while (true) {
		if (s.size() && s[0] == '0') {
			s.erase(s.begin());
		}
		else {
			break;
		}
	}
	if (s.size() == 0) res.push_back("0");
	else {
		res.push_back(s);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	regex re("\\d");

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		string temp;
		for (int j = 0; j < s.size(); j++) {
			if (regex_match(s.substr(j, 1), re)) {
				temp += s[j];
			}
			else if (temp.size() != 0) {
				save_res(temp);
				temp = "";
			}
		}
		save_res(temp);
	}
	sort(res.begin(), res.end(), cmp);
	for (string i : res) {
		cout << i << "\n";
	}
	return 0;
}