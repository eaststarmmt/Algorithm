#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int get_answer(vector<string>& name, vector<int>& yearning, vector<string>& photo) {
	int sum = 0;
	for (int i = 0; i < photo.size(); i++) {
		int idx = find(name.begin(), name.end(), photo[i]) - name.begin();

		if (idx == name.size()) continue;
		sum += yearning[idx];
	}

	return sum;
}

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
	vector<int> answer;
	for (int i = 0; i < photo.size(); i++) {
		answer.push_back(get_answer(name, yearning, photo[i]));
	}
	return answer;
}