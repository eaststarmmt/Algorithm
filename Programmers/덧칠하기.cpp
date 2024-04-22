#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
	int answer = 1;
	int idx = section[0] + m - 1;
	for (int i = 1; i < section.size(); i++) {
		if (section[i] <= idx) continue;
		idx = section[i] + m - 1;
		answer++;
	}

	return answer;
}