#include <string>
#include <vector>
#include <sstream>
using namespace std;

int cnt[2];

string solution(string polynomial) {
	string answer = "";
	stringstream stream(polynomial);
	string s;

	while (stream >> s) {
		if (s == "+") continue;
		else if (s == "x") cnt[0]++;
		else if (s[s.size() - 1] == 'x') cnt[0] += stoi(s.substr(0, s.size() - 1));
		else cnt[1] += stoi(s);
	}   // end of while

	if (cnt[0] == 1) answer = "x";
	else if (cnt[0]) answer = to_string(cnt[0]) + "x";

	if (answer.size() && cnt[1]) answer += " + ";
	if (cnt[1]) answer += to_string(cnt[1]);
	return answer;
}