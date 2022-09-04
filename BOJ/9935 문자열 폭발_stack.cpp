#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
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
	stack<char> stk;
	for (char c : s) {
		stk.push(c);
		if (stk.size() < expos.size()) continue;
		if (expos[expos.size() - 1] != stk.top()) continue;	// 끝 글자 안맞으면 어차피 다를거라 그냥 거름

		string temp;
		for (int i = 0; i < expos.size(); i++) {		// expos 만큼 위에서 뽑아서 맞는지 확인
			temp += stk.top();
			stk.pop();
		}	// end of for stk

		reverse(temp.begin(), temp.end());

		if (temp == expos) continue;

		for (char t : temp) {	// 틀리면 다시 넣기
			stk.push(t);
		}	// end of for temp

	}	// end of for s

	if (stk.empty()) {
		cout << "FRULA\n";
	}
	else {
		string res;

		while (!stk.empty()) {
			res += stk.top();
			stk.pop();
		}	// end of for stk

		reverse(res.begin(), res.end());
		cout << res << "\n";
	}
	return 0;
}