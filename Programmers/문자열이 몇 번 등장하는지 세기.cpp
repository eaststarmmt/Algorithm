#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
	int answer = 0;
	while (myString.size() >= pat.size()) {
		int idx = myString.find(pat);
		if (idx == string::npos) break;
		myString = myString.substr(idx + 1);
		answer++;
	}   // end of while
	return answer;
}