#include <string>
#include <vector>

using namespace std;

int cnt[204];

int solution(vector<vector<int>> lines) {
	int answer = 0;
	for (int i = 0; i < lines.size(); i++) {
		int lo = lines[i][0];
		int hi = lines[i][1];

		for (int j = lo; j < hi; j++) {
			cnt[j + 100]++;
		}
	}

	for (int i = 0; i <= 200; i++) {
		if (cnt[i] > 1) answer++;
	}
	return answer;
}