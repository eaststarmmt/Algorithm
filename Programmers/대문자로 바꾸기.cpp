#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string myString) {
	string answer = "";
	for (char c : myString) {
		answer += toupper(c);
	}
	return answer;
}