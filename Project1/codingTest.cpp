#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int product[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 1000000 };
	int N, K;
	string input;
	cin >> N >> K >> input;
	stack<int> stk;
	int cnt = K;

	if (N == K) return 0;

	for (int i = 0; i < N; i++) {
		
		while (K > 0 && !stk.empty() && stk.top() < input[i] -'0') {
			stk.pop();
			K--;
		}

		stk.push(input[i] - '0');
	}

	vector<int> result;
	int limit = stk.size();
	for (int i = 0; i < limit; i++) {
		result.push_back(stk.top());
		stk.pop();
	}
	for (int i = limit - 1; i >= 0; i--) {
		cout << result[i];
	}

	cout << "\n";
}