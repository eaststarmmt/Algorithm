#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int psum[204];

vector<int> solution(int num, int total) {
	vector<int> answer;
	answer.push_back(total / num);
	int flag = 0;
	if (total % num != 0) {
		answer.push_back(total / num + 1);
		flag = 1;
	}

	for (int i = 1; i <= num / 2; i++) {
		if (answer.size() == num) break;
		answer.push_back(total / num + i + flag);
		answer.push_back(total / num - i);
	}

	sort(answer.begin(), answer.end());
	return answer;
}