#include <string>
#include <vector>

using namespace std;

int alpha[30], alpha2[30];

int solution(string before, string after) {
	int answer = 1;
	for (int i = 0; i < before.size(); i++) {
		alpha[before[i] - 'a']++;
		alpha2[after[i] - 'a']++;
	}

	for (int i = 0; i < 30; i++) {
		if (alpha[i] != alpha2[i]) {
			answer = 0;
			break;
		}
	}
	return answer;
}