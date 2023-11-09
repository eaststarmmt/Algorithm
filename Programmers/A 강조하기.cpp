#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
	string answer = "";
	for (char c : myString) {
		if (c == 'A' || c == 'a') answer += 'A';
		else answer += tolower(c);
	}
	return answer;
}