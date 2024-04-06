#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string A, string B) {
	int answer = -1;
	if (A == B) return 0;
	for (int i = 1; i < A.size(); i++) {
		rotate(A.begin(), A.end() - 1, A.end());
		if (A == B) {
			answer = i;
			break;
		}
	}
	return answer;
}