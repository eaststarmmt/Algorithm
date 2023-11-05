#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> solution(string my_string) {
	vector<string> answer;
	stringstream stream(my_string);
	string s;
	while (stream >> s) {
		answer.push_back(s);
	}
	return answer;
}