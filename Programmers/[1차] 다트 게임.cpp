#include <string>
#include <vector>
#include <regex>
#include <cmath>
using namespace std;

int solution(string dartResult) {
	int answer = 0;
	vector<int> score;
	string now_score;
	regex bound("[SDT]");
	regex opt("[*#]");
	for (int i = 0, now = -1; i < dartResult.size(); i++) {
		if (isdigit(dartResult[i])) {
			now_score += dartResult[i];
			continue;   // if 블록 깊어지면 헷갈려서 else 하나라도 줄이기 위해
		}
		if (!now_score.empty()) {
			score.push_back(stoi(now_score));
			now_score = "";
			now++;
		}
		if (regex_match(dartResult.substr(i, 1), bound)) {
			int x;
			if (dartResult[i] == 'S') {
				x = 1;
			}
			else if (dartResult[i] == 'D') {
				x = 2;
			}
			else {
				x = 3;
			}
			score[now] = pow(score[now], x);
		}   // end of if bound
		else if (regex_match(dartResult.substr(i, 1), opt)) {
			if (dartResult[i] == '*') {
				score[now] *= 2;
				if (now) {   // 처음 나온 숫자 아니면 이전 숫자도 두배 
					score[now - 1] *= 2;
				}
			}
			else {
				score[now] *= -1;
			}
		}
	}
	for (int x : score) {
		answer += x;
	}
	return answer;
}