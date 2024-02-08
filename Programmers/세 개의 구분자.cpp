#include <string>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

vector<string> split(string s) {
	stringstream stream(s);
	string temp;
	vector<string> v;

	while (stream >> temp) {
		v.push_back(temp);
	}
	return v;
}

vector<string> solution(string myStr) {
	vector<string> answer;
	string s = regex_replace(myStr, regex("[abc]"), " ");
	answer = split(s);

	if (answer.empty()) answer.push_back("EMPTY");
	return answer;
}