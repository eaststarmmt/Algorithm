#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(char a, char b) {
	return a > b;
}

string solution(string s) {
	string answer = "";
	sort(s.begin(), s.end(), cmp);
	answer = s;
	return answer;
}