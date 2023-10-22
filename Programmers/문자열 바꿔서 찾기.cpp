#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
	int answer = 0;
	for (int i = 0; i < myString.size(); i++) {
		if (myString[i] == 'A') myString[i] = 'B';
		else if (myString[i] == 'B') myString[i] = 'A';
	}

	answer = myString.find(pat) == string::npos ? 0 : 1;
	return answer;
}