#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
	string answer = "";

	for (int i = 1; i < numLog.size(); i++) {
		int x = numLog[i] - numLog[i - 1];
		if (x == 1) {
			answer += 'w';
		}
		else if (x == -1) {
			answer += 's';
		}
		else if (x == 10) {
			answer += 'd';
		}
		else {
			answer += 'a';
		}
	}
	return answer;
}