#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
	vector<int> answer(arr.begin(), arr.end());
	for (int i = 0; i < queries.size(); i++) {
		int start = queries[i][0];
		int end = queries[i][1];

		swap(answer[start], answer[end]);
	}
	return answer;
}