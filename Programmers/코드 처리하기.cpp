#include <string>
#include <vector>

using namespace std;

string solution(string code) {
	string answer = "";
	int mode = 0;
	for (int i = 0; i < code.size(); i++) {
		char c = code[i];
		if (c == '1') mode = !mode;
		else if (!mode && !(i & 1)) answer += c;
		else if (mode && (i & 1)) answer += c;
	}
	answer = answer.size() ? answer : "EMPTY";
	return answer;
}