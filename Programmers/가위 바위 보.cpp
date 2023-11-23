#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, char> m = {
	{'2', '0'},
	{'0', '5'},
	{'5', '2'}
};

string solution(string rsp) {
	string answer = "";

	for (char c : rsp) {
		answer += m[c];
	}
	return answer;
}