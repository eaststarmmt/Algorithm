#include <string>
#include <vector>

using namespace std;

int cnt[200];

vector<int> solution(string my_string) {
	vector<int> answer;
	for (char c : my_string) {
		cnt[c]++;
	}

	for (char c = 'A'; c <= 'Z'; c++) {
		answer.push_back(cnt[c]);
	}
	for (char c = 'a'; c <= 'z'; c++) {
		answer.push_back(cnt[c]);
	}
	return answer;
}