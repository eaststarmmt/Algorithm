#include <string>
#include <vector>

using namespace std;

void add_row(vector<vector<int>>& arr, int R) {
	for (int i = 0; i < arr.size(); i++) {
		arr[i].resize(R, 0);
	}
}

void add_col(vector<vector<int>>& arr, int R, int C) {
	for (int i = 0; i < C - R; i++) {
		vector<int> v(C, 0);
		arr.push_back(v);
	}
}

vector<vector<int>> solution(vector<vector<int>> arr) {
	vector<vector<int>> answer = arr;
	int R = arr.size();
	int C = arr[0].size();

	if (R > C) {
		add_row(answer, R);
	}
	else if (R < C) {
		add_col(answer, R, C);
	}

	return answer;
}