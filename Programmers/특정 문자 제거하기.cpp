#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
	string answer = "";
	for (char c : my_string) {
		if (c == letter[0]) continue;
		answer += c;
	}
	return answer;
}