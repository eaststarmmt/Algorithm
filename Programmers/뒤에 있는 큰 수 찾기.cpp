#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer(numbers.size(), -1);
	stack<int> stk;
	for (int i = numbers.size() - 1; i >= 0; i--) {
		int x = numbers[i];
		while (!stk.empty() && stk.top() <= x) {
			stk.pop();
		}

		if (!stk.empty()) {
			answer[i] = stk.top();
		}
		stk.push(x);
	}
	return answer;
}