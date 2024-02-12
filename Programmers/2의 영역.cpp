#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;
	auto idx = find(arr.begin(), arr.end(), 2);

	if (idx == arr.end()) return { -1 };

	answer = vector<int>(idx, arr.end());

	for (int i = answer.size() - 1; i >= 0; i--) {
		if (answer[i] == 2) break;
		answer.pop_back();
	}   // end of for

	return answer;
}