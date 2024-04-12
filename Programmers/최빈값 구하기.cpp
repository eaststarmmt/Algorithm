#include <string>
#include <vector>

using namespace std;

int cnt[1004];

int solution(vector<int> array) {
	int answer = 0;

	for (int x : array) {
		cnt[x]++;
	}

	for (int i = 1, val = 0; i <= 1000; i++) {
		if (cnt[i] == cnt[val]) answer = -1;
		else if (cnt[i] > cnt[val]) {
			val = i;
			answer = i;
		}
	}

	return answer;
}