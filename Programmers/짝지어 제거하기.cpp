#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
	int answer = -1;

	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	cout << "Hello Cpp" << endl;
	stack<char> stk;
	for (int i = 0; i < s.size(); i++) {
		if (stk.empty())     // ��������� push
			stk.push(s[i]);
		else if (stk.top() == s[i])  // top�� ���� ���ڸ� ���� �ʰ� pop
			stk.pop();
		else                // ����ִµ� �ٸ��� push
			stk.push(s[i]);
	}
	if (stk.empty()) // ������ ��� ������ ����
		answer = 1;
	else            // ��������� �Ұ���
		answer = 0;
	return answer;
}