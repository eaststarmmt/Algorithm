#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, string> m;

void setMap() {
	m["zero"] = "0";
	m["one"] = "1";
	m["two"] = "2";
	m["three"] = "3";
	m["four"] = "4";
	m["five"] = "5";
	m["six"] = "6";
	m["seven"] = "7";
	m["eight"] = "8";
	m["nine"] = "9";
}

int solution(string s) {
	int answer = 0;
	setMap();

	string res, cur;

	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {     // 숫자인지 확인. 숫자면 그냥 넣기
			res += s[i];
		}
		else {
			cur += s[i];
			if (m[cur] != "") {      // 문자인 경우 맵에 있으면 추가하고 cur 비워주기
				res += m[cur];
				cur = "";
			}
		}
	}   // end of for
	answer = stoi(res);
	return answer;
}