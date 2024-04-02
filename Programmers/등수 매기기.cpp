#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
	vector<int> answer;
	vector<int> v;
	for (int i = 0; i < score.size(); i++) {
		int x = score[i][0] + score[i][1];
		v.push_back(x);
	}

	for (int i = 0; i < v.size(); i++) {
		int rank = 1;
		for (int j = 0; j < v.size(); j++) {
			if (i == j) continue;
			if (v[i] < v[j]) rank++;
		}
		answer.push_back(rank);
	}

	return answer;
}