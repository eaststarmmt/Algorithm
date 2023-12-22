#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
	int answer = 0;
	stack<int> stk;
	int idx = 1;

	for (int i = 0; i < order.size(); i++) {
		int x = order[i];
		while (x > idx) {
			stk.push(idx++);
		}
		if (idx == x) {
			answer++;
			idx++;
		}
		else if (stk.empty()) break;
		else if (x == stk.top()) {
			answer++;
			stk.pop();
		}
		else break;
	}
	return answer;
}