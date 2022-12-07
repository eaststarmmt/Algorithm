#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	int idx = -1;
	int flag = 0;   // 첫 문자 초기화 되었는지 확인하는 flag
	char c;
	int scnt = 0;   // 시작 문자 개수
	int dcnt = 0;   // 끝 문자 개수
	while (++idx < s.size()) {
		if (!flag) {
			c = s[idx];
			dcnt = 0;
			scnt = 1;
			flag = 1;
			continue;
		}
		c == s[idx] ? scnt++ : dcnt++;
		if (scnt == dcnt) {
			answer++;
			flag = 0;
		}
	}   // end of while
	if (flag) {
		answer++;
	}
	return answer;
}