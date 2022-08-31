#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int d[200004];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	stack<int> stk;
	string s;
	cin >> s;
	for (int i = 0; i < N; i++) {
		if (s[i] == '(') {	// ( 일때 넣기만 하고 표시를 안해서 짝 안맞는 경우 방지
			stk.push(i);
		}
		else if (!stk.empty()) {	// top('(') 하고 현 위치(')') 짝이 있는 경우만 표시
			d[stk.top()] = d[i] = 1;
			stk.pop();
		}
	}	// end of for i

	int cnt, res;
	cnt = res = 0;

	for (int i = 0; i < N; i++) {
		if (d[i]) {
			cnt++;
			res = max(cnt, res);
		}
		else {
			cnt = 0;
		}
	}	// end of for i

	cout << res << "\n";
	return 0;
}