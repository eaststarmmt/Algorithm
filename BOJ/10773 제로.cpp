#include<iostream>
#include<stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int> stk;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			sum -= stk.top();
			stk.pop();
		}
		else {
			stk.push(x);
			sum += stk.top();
			
		}
	}
	cout << sum << endl;
}