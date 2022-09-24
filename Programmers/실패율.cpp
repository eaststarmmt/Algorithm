#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cnt[510];

bool cmp(pair<double, int>& A, pair<double, int>& B) {
	if (A.first == B.first) {
		return A.second < B.second;
	}
	return A.first > B.first;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	for (int i = 0; i < stages.size(); i++) {
		cnt[stages[i]]++;   // 스테이지에 멈춘 인원 카운팅
	}   // end of for

	int sum = cnt[N + 1];
	vector<pair<double, int>> fail;
	for (int i = N; i >= 1; i--) {
		sum += cnt[i];
		if (sum == 0) {
			fail.push_back({ 0, i });
		}
		else {
			fail.push_back({ (double)cnt[i] / sum, i });
		}
	}

	sort(fail.begin(), fail.end(), cmp);
	for (pair<double, int> x : fail) {
		answer.push_back(x.second);
	}
	return answer;
}