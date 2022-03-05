#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	int n;
	stack<int> stk;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "push") {
			int x;
			cin >> x;
			stk.push(x);
		}
		else if (command == "pop") {
			if (stk.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << stk.top() << endl;
				stk.pop();
			}
		}
		else if (command == "size") {
			cout << stk.size() << endl;
		}
		else if (command == "empty") {
			if (stk.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else {
			if (stk.empty()) {
				cout << -1 << endl;
			}
			else cout << stk.top() << endl;
		}
	}
}