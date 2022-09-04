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
		if (expos[expos.size() - 1] != stk.top()) continue;	// �� ���� �ȸ����� ������ �ٸ��Ŷ� �׳� �Ÿ�

		string temp;
		for (int i = 0; i < expos.size(); i++) {		// expos ��ŭ ������ �̾Ƽ� �´��� Ȯ��
			temp += stk.top();
			stk.pop();
		}	// end of for stk

		reverse(temp.begin(), temp.end());

		if (temp == expos) continue;

		for (char t : temp) {	// Ʋ���� �ٽ� �ֱ�
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