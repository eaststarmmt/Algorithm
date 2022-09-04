#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	string expos;
	cin >> expos;
	string res;
	// pivot 알고리즘. res에 문자 하나씩 추가하면서 끝 문자 잘라서 expos와 일치하는지 비교
	for (char c : s) {
		res += c;
		if (res.size() < expos.size()) continue;
		int idx = res.size() - expos.size();
		if (res.substr(idx) == expos) {
			res.erase(idx);
		}
	}	// end of for

	if (res.empty()) {
		cout << "FRULA\n";
	}
	else {
		cout << res << "\n";
	}
	return 0;
}