#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
	vector<int> answer(arr.begin(), arr.end());

	for (int i = 0; i < query.size(); i++) {
		if (i & 1) {
			answer.erase(answer.begin(), answer.begin() + query[i]);
		}
		else {
			answer.erase(answer.begin() + query[i] + 1, answer.end());
		}

	}
	return answer;
}