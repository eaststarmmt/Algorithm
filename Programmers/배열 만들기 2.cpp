#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int l, int r) {
	vector<int> answer;
	queue<int> Q({ 5 });

	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		if (x >= l && x <= r) answer.push_back(x);
		else if (x > r) break;
		Q.push(x * 10);
		Q.push(x * 10 + 5);
	}
	if (answer.empty()) answer.push_back(-1);
	return answer;
}