#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
	string answer = "";
	for (char c : my_string) {
		if (c <= 'Z') answer += tolower(c);
		else answer += toupper(c);
	}
	return answer;
}