#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
	int answer = 0;

	for (int i = 0; i < sizes.size(); i++) {
		sort(sizes[i].begin(), sizes[i].end());
	}

	vector<int> r, c;
	for (int i = 0; i < sizes.size(); i++) {
		c.push_back(sizes[i][0]);
		r.push_back(sizes[i][1]);
	}

	answer = (*max_element(c.begin(), c.end())) * (*max_element(r.begin(), r.end()));
	return answer;
}