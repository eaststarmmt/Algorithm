#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;
	for (int i = 0; i < arr.size(); i++) {
		int x = arr[i];
		if (answer.empty()) answer.push_back(x);
		else if (x == answer[answer.size() - 1]) answer.pop_back();
		else answer.push_back(x);
	}

	if (answer.empty()) answer.push_back(-1);
	return answer;
}