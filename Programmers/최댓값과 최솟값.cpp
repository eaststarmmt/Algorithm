#include <string>
#include <vector>
#include <sstream>
using namespace std;

string solution(string s) {
	string answer = "";
	stringstream stream(s);
	string num;
	int max = -1e9;
	int min = 1e9;
	while (stream >> num) {
		max = stoi(num) > max ? stoi(num) : max;
		min = stoi(num) < min ? stoi(num) : min;
	}
	answer = to_string(min) + " " + to_string(max);
	return answer;
}