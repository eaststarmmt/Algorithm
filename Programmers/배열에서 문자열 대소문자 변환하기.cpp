#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
	vector<string> answer;
	for (int i = 0; i < strArr.size(); i++) {
		string s;
		for (int j = 0; j < strArr[i].size(); j++) {
			if (i % 2) {
				s += toupper(strArr[i][j]);
			}
			else {
				s += tolower(strArr[i][j]);
			}
		}   // end of for j
		answer.push_back(s);
	}
	return answer;
}