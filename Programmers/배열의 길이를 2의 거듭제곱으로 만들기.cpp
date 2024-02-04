#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer(arr.begin(), arr.end());
	for (int i = 1; i < 1100; i <<= 1) {
		if (i < arr.size()) continue;
		for (int j = arr.size(); j < i; j++) {
			answer.push_back(0);
		}
		break;
	}
	return answer;
}