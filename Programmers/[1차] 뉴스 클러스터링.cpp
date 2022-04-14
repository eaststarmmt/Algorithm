#include <string>
#include <regex>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> inter;   // 교집합
vector<string> joint;   // 합집합

void spare(int& s_idx, vector<string>& s) { // 남은 원소들 합집합에 다 넣기
	for (int i = s_idx; i < s.size(); i++) {
		joint.push_back(s[i]);
	}
}

void classified(string str, vector<string>& s1) {   // 두 글자씩 잘라서 넣기
	regex re("^[a-z]+$");    // 영문 체크할 정규식
	for (int i = 0; i < str.size() - 1; i++) {
		string s = str.substr(i, 2);
		if (regex_match(s, re)) {   // 영문으로 되어있는 것만 push
			s1.push_back(s);
		}
	}   // end of for
}

void to_lower(string& str) {    // 모든 문자 소문자로 변환
	for (int i = 0; i < str.size(); i++) {
		str[i] = tolower(str[i]);
	}
}

int solution(string str1, string str2) {
	int answer = 0;
	to_lower(str1);
	to_lower(str2);

	vector<string> s1, s2;  // 원소 나누기
	classified(str1, s1);
	classified(str2, s2);

	if (s1.size() == 0 && s2.size() == 0) return 65536; // 원소 없으면 1로 가정하고 return

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	int s1_idx = 0;
	int s2_idx = 0;
	// 두 문자 비교
	while (s1_idx < s1.size() && s2_idx < s2.size()) {
		if (s1[s1_idx] == s2[s2_idx]) {  // 같은게 있는 경우
			inter.push_back(s1[s1_idx]);
			joint.push_back(s1[s1_idx++]);
			s2_idx++;
		}
		else {    // 다른 경우 둘 중에 알파벳 빠른놈 넣고 인덱스 올리기
			string temp = s1[s1_idx] < s2[s2_idx] ? s1[s1_idx++] : s2[s2_idx++];
			joint.push_back(temp);
		}
	}   // end of while
	// 인덱스를 끝까지 못 간 애들 전부 합집합에 넣기
	spare(s1_idx, s1);
	spare(s2_idx, s2);
	// double로 소수점 구하고 65536 곱해서 int로 소수점 버리기
	double ans = (double)inter.size() / joint.size();
	answer = ans * 65536;

	return answer;
}