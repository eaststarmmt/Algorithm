#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	string input;		// 숫자를 한자리씩 나누기 위해 string으로 받음
	cin >> N >> K >> input;
	stack<int> stk;
	int cnt = K;

	if (N == K) return 0;		// ex 1자리에서 1개 지우면 출력할게 없음

	for (int i = 0; i < N; i++) {
		
		while (K > 0 && !stk.empty() && stk.top() < input[i] -'0') {	// K가 0보다 크다는 조건이 없으면 필요 이상으로 지워짐. top보다 다음 숫자가 크면 스택에서 비움
			stk.pop();
			K--;
		}

		stk.push(input[i] - '0');
	}

	vector<int> result;
	int limit = stk.size();

	while (true) {
		result.push_back(stk.top());
		stk.pop();
		if (stk.empty()) break;
	}
	for (int i = result.size() - 1; i >= 0 + K; i--) {		// K가 완전히 소거되지 않았을 경우를 대비해 +K로 잡음
		cout << result[i];
	}

	cout << "\n";
}