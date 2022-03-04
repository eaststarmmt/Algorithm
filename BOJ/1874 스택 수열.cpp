#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int> stk;
	vector<int> vec;
	vector<char> result;
	int input = 1;
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
	}
	int cnt = 0;
	stk.push(input);
	result.push_back('+');
	while (1) {
		if (stk.top() < vec[cnt]) {
			result.push_back('+');
			input++;
			stk.push(input);
		}
		else if (stk.top() == vec[cnt]) {
			stk.pop();
			result.push_back('-');
			cnt++;
		}
		else {
			cout << "NO" << endl;
			return 0;
		}
		if (stk.empty() && input == n) break;
		if (stk.empty() && input != n) {
			input++;
			stk.push(input);
			result.push_back('+');
		}
	}
	for (int i = 0; i < result.size(); i++) cout << result[i] << endl;
}