#include <string>
#include <vector>
#include <regex>

using namespace std;

bool solution(string s) {
	bool answer = true;
	if (s.size() != 4 && s.size() != 6) return false;
	regex re("^[0-9]*$");
	regex_match(s, re) ? answer = true : answer = false;
	return answer;
}