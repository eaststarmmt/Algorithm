#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string my_string) {
	int answer = 0;
	stringstream ss(my_string);
	string s;

	ss >> s;
	answer = stoi(s);

	while (ss >> s) {
		string num;
		ss >> num;

		if (s == "+") {
			answer += stoi(num);
		}
		else {
			answer -= stoi(num);
		}
	}
	return answer;
}