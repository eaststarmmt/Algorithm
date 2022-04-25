#include <string>
#include <vector>
#include <stack>
using namespace std;

bool check(string target) { // 맞는 괄호인지 확인. 중괄호 대괄호 우선순위 상관 없음
	stack<char> stk;
	for (int i = 0; i < target.size(); i++) {
		if (target[i] == '(' || target[i] == '{' || target[i] == '[') {
			stk.push(target[i]);
		}
		else if (stk.empty()) {
			return false;
		}
		else if (stk.top() == '(' && target[i] == ')') {
			stk.pop();
		}
		else if (stk.top() == '{' && target[i] == '}') {
			stk.pop();
		}
		else if (stk.top() == '[' && target[i] == ']') {
			stk.pop();
		}
		else {
			return false;
		}
	}   // end of for
	if (!stk.empty()) return false;
	return true;
}

int solution(string s) {
	int answer = 0;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		string target = s.substr(i, len - i) + s.substr(0, i); // 문자열 회전
		if (check(target)) answer++;
	}   // end of for

	return answer;
}