#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
	vector<int> answer(arr.begin(), arr.end());
	for (vector<int> x : queries) {
		for (int i = x[0]; i <= x[1]; i++) {
			answer[i]++;
		}
	}
	return answer;
}