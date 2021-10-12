#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	string input;		// ���ڸ� ���ڸ��� ������ ���� string���� ����
	cin >> N >> K >> input;
	stack<int> stk;
	int cnt = K;

	if (N == K) return 0;		// ex 1�ڸ����� 1�� ����� ����Ұ� ����

	for (int i = 0; i < N; i++) {
		
		while (K > 0 && !stk.empty() && stk.top() < input[i] -'0') {	// K�� 0���� ũ�ٴ� ������ ������ �ʿ� �̻����� ������. top���� ���� ���ڰ� ũ�� ���ÿ��� ���
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
	for (int i = result.size() - 1; i >= 0 + K; i--) {		// K�� ������ �Ұŵ��� �ʾ��� ��츦 ����� +K�� ����
		cout << result[i];
	}

	cout << "\n";
}