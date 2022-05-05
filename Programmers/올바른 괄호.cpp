#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
	bool answer = true;
	stack<char> stk;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {   // 열린 괄호 조건
			stk.push(s[i]);
		}
		else if (stk.empty()) {
			answer = false;
			break;
		}
		else if (stk.top() == '(') {
			stk.pop();
		}
		else {
			stk.push(s[i]);
		}
	}   // end of for
	if (!stk.empty()) {
		answer = false;
	}

	return answer;
}