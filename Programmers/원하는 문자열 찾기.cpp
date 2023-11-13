#include <string>
#include <vector>

using namespace std;

string to_lower(string s) {
	string res;

	for (char c : s) {
		res += tolower(c);
	}

	return res;
}

int solution(string myString, string pat) {
	myString = to_lower(myString);
	pat = to_lower(pat);

	int answer = myString.find(pat) != string::npos;
	return answer;
}