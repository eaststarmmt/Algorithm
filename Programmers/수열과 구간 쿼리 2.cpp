#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
	vector<int> answer;

	for (int i = 0; i < queries.size(); i++) {
		int s = queries[i][0];
		int e = queries[i][1];
		int k = queries[i][2];

		int idx = -1;
		int m = 1e9;

		for (int j = s; j <= e; j++) {
			if (arr[j] > k && arr[j] < m) {
				idx = j;
				m = arr[j];
			}
		}

		if (m == 1e9) answer.push_back(-1);
		else answer.push_back(m);
	}   // end of for
	return answer;
}