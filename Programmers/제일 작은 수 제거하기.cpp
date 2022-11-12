#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;
	int min_val = arr[0];
	int min_idx = 0;
	for (int i = 1; i < arr.size(); i++) {
		if (min_val > arr[i]) {
			min_val = arr[i];
			min_idx = i;
		}
	}   // end of for
	for (int i = 0; i < arr.size(); i++) {
		if (min_idx == i) continue;
		answer.push_back(arr[i]);
	}
	if (answer.empty()) answer.push_back(-1);
	return answer;
}