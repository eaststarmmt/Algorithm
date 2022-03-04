#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	while (1) {
		string n;
		stack<char> stk;
		bool flag = true;
		getline(cin, n);
		if (n == ".") {
			break;
		}
		for (int i = 0; i < n.size(); i++) {
			if (n[i] == '(') {
				stk.push('(');
			}
			else if (n[i] == ')') {
				if (stk.empty() || stk.top() != '(') {
					cout << "no" << endl;
					flag = false;
					break;
				}
				else {
					stk.pop();
				}
			}
			else if (n[i] == '[') {
				stk.push('[');
			}
			else if (n[i] == ']') {
				if (stk.empty() || stk.top() != '[') {
					cout << "no" << endl;
					flag = false;
					break;
				}
				else {
					stk.pop();
				}
			}
		}
		if (flag) {
			if (stk.empty()) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}
}