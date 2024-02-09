#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
	vector<int> answer(arr.begin(), arr.end());
	for (int i = 0; i < queries.size(); i++) {
		int s = queries[i][0];
		int e = queries[i][1];
		int k = queries[i][2];

		for (int j = s; j <= e; j++) {
			if (j % k == 0) answer[j]++;
		}
	}
	return answer;
}