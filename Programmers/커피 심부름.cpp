#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
	int answer = 0;
	for (string s : order) {
		if (s.find("americano") != string::npos || s == "anything") answer += 4500;
		else answer += 5000;
	}
	return answer;
}