#include <string>
#include <vector>
#include <stack>
using namespace std;

// �ùٸ� ���ڿ� üũ �Լ�
bool correct(string p) {
	stack<char> stk;
	if (p[0] == ')')     // ������ �ݴ� ��ȣ�� �ùٸ��� ����
		return false;

	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') {    // ���� ��ȣ�� �ϴ� ���⼭ �ɷ���. �ڴ� �� �ݴ� ��ȣ�� ����� �����ϸ� ��
			stk.push(p[i]);
		}
		else if (stk.empty()) {  // �ݴ� ��ȣ ���Դµ� ���� ������� �׳� �ɷ��� ��
			return false;
		}
		else if (stk.top() == '(') {
			stk.pop();
		}
		else {    // ������ ��� �׳� ���� ����
			stk.push(p[i]);
		}
	}   // end of for
	if (stk.empty()) return true;    // ������ ��������� �ùٸ� ���
	return false;

}

// �ܾ� �������ִ� �Լ�
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
	int open = 0;   // ���� ��ȣ�� �ݴ� ��ȣ ���� ����
	int close = 0;

	for (int i = 0; i < p.size(); i++) { // �������� ��ȣ �����
		if (p[i] == '(') open++;
		else close++;
		if (open == close) break;    // ��ȣ ���� ������ Ż��
	}   // end of for

	string u = p.substr(0, open + close);
	string v = p.substr(open + close);

	if (correct(u)) {    // u�� �ùٸ� ���ڿ��� ���
		answer = u + recursive(v);
	}
	else {        // �ùٸ��� ���� ���ڿ��� ���
		answer = "(" + recursive(v) + ")";   // ��� ���ļ� ���̿� ����
		string temp = reverse(u);           // ���Ǵ�� ����� ����
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