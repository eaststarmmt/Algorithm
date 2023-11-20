#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr) {
	int answer = 1;
	for (int i = 0; i < arr.size(); i++) {
		if (!answer) break;
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] != arr[j][i]) {
				return 0;
			}
		}
	}
	return answer;
}