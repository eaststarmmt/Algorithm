#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
	string answer = "";
	for (char c : myString) {
		if (c <= 'l') answer += 'l';
		else answer += c;
	}
	return answer;
}