#include <string>
#include <vector>
#include <stack>
using namespace std;

// 올바른 문자열 체크 함수
bool correct(string p) {
	stack<char> stk;
	if (p[0] == ')')     // 시작이 닫는 괄호면 올바를수 없음
		return false;

	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') {    // 여는 괄호은 일단 여기서 걸러짐. 뒤는 다 닫는 괄호의 경우라고 생각하면 됨
			stk.push(p[i]);
		}
		else if (stk.empty()) {  // 닫는 괄호 나왔는데 스택 비었으면 그냥 걸러도 됨
			return false;
		}
		else if (stk.top() == '(') {
			stk.pop();
		}
		else {    // 나머지 경우 그냥 집어 넣음
			stk.push(p[i]);
		}
	}   // end of for
	if (stk.empty()) return true;    // 스택이 비어있으면 올바른 경우
	return false;

}

// 단어 뒤집어주는 함수
string reverse(string p) {
	string answer = "";
	for (int i = 1; i < p.size() - 1; i++) {
		if (p[i] == '(') answer += ')';
		else answer += '(';
	}
	return answer;
}

string recursive(string p) {
	string answer = "";
	if (p.size() == 0) return p;
	int open = 0;   // 여는 괄호와 닫는 괄호 개수 세기
	int close = 0;

	for (int i = 0; i < p.size(); i++) { // 균형잡힌 괄호 만들기
		if (p[i] == '(') open++;
		else close++;
		if (open == close) break;    // 괄호 개수 맞으면 탈출
	}   // end of for

	string u = p.substr(0, open + close);
	string v = p.substr(open + close);

	if (correct(u)) {    // u가 올바른 문자열인 경우
		answer = u + recursive(v);
	}
	else {        // 올바르지 않은 문자열인 경우
		answer = "(" + recursive(v) + ")";   // 재귀 거쳐서 사이에 넣음
		string temp = reverse(u);           // 조건대로 뒤집어서 넣음
		answer += temp;
	}
	return answer;
}

string solution(string p) {
	string answer = "";
	if (p.size() == 0) return answer;
	answer = recursive(p);
	return answer;
}