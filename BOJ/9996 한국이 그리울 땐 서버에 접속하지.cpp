#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	string pattern;
	cin >> pattern;

	int idx = pattern.find("*");
	string pre = pattern.substr(0, idx);
	string suf = pattern.substr(idx + 1);

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (pre.size() + suf.size() > s.size()) {	// 중간 글자 없는 예외 걸러내기
			cout << "NE" << "\n";
		}
		else {
			if (pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) {
				cout << "DA\n";
			}
			else {
				cout << "NE\n";
			}
		}

	}
	return 0;
}