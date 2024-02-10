#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt[31];

int solution(vector<string> strArr) {
	int answer = 0;

	for (string s : strArr) {
		cnt[s.size()]++;
	}   // end of for

	answer = *max_element(cnt, cnt + 31);

	return answer;
}