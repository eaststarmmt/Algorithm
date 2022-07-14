#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int res = 0;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		stack<char> stk;

		for (int j = 0; j < s.size(); j++) {
			if (stk.size() && stk.top() == s[j]) {	// pop의 경우를 먼저 체크하면 코드가 짧아짐
				stk.pop();
			}
			else {
				stk.push(s[j]);
			}
		}
		if (stk.empty()) {
			res++;
		}
	}
	cout << res << "\n";
}