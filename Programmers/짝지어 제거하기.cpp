#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
	int answer = -1;

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "Hello Cpp" << endl;
	stack<char> stk;
	for (int i = 0; i < s.size(); i++) {
		if (stk.empty())     // 비어있으면 push
			stk.push(s[i]);
		else if (stk.top() == s[i])  // top과 같은 글자면 넣지 않고 pop
			stk.pop();
		else                // 들어있는데 다르면 push
			stk.push(s[i]);
	}
	if (stk.empty()) // 스택이 비어 있으면 가능
		answer = 1;
	else            // 들어있으면 불가능
		answer = 0;
	return answer;
}