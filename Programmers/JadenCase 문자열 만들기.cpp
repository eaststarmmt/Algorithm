#include <string>
#include <vector>
#include <regex>
using namespace std;

string getHead(string s) {  // 첫 글자 대문자인지 숫자인지 판단
	regex re("\\d");
	string head = "";

	if (regex_match(s.substr(0, 1), re)) {
		head = s[0];
	}
	else {
		head = toupper(s[0]);
	}

	return head;
}

string tolowers(string s) { // 나머지 글자들 소문자로 변환
	string low;
	for (int i = 0; i < s.size(); i++) {
		low += tolower(s[i]);
	}
	return low;
}

string solution(string s) {
	string answer = "";
	regex word("\\w");  // 모든 문자
	regex white("\\s"); // 공백
	string temp;
	for (int i = 0; i < s.size(); i++) {
		if (regex_match(s.substr(i, 1), word)) { // 단어인 경우 temp로 따로 분리
			temp += s[i];
		}
		else if (regex_match(s.substr(i, 1), white)) { // 공백인 경우
			if (temp != "") {            // temp에 단어가 남아있으면 JadenCase에 맞게 저장
				answer += getHead(temp);
				answer += tolowers(temp.substr(1));
				temp = "";
			}
			answer += ' ';      // 공백 더해주기
		}
	}
	if (temp != "") {    // 마지막 글자가 포함 안되서 따로 해줌
		answer += getHead(temp);
		answer += tolowers(temp.substr(1));
	}
	return answer;
}