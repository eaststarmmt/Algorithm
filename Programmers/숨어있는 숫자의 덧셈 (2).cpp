#include <string>
#include <vector>
#include <regex>
#include <sstream>

using namespace std;

int solution(string my_string) {
	int answer = 0;
	string s = regex_replace(my_string, regex("[^0-9]"), " ");
	stringstream ss(s);
	string temp;

	while (ss >> temp) {
		answer += stoi(temp);
	}
	return answer;
}