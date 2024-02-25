#include <string>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

int solution(string s) {
	int answer = 0;
	stack<int> stk;
	stringstream stream(s);
	string input;

	while (stream >> input) {
		if (input == "Z") stk.pop();
		else stk.push(stoi(input));
	}   // end of while

	while (!stk.empty()) {
		answer += stk.top();
		stk.pop();
	}   // end of while

	return answer;
}