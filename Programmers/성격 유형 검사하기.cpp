#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
	string answer = "";
	map<char, int> m;
	for (int i = 0; i < survey.size(); i++) {
		int choice = choices[i];
		if (choice < 0) {
			m[survey[i][0]] += 4 - choice;
		}
		else if (choice > 0) {
			m[survey[i][1]] += choice - 4;
		}
	}   // end of for

	if (m['R'] < m['T']) answer += 'T';
	else answer += 'R';
	if (m['C'] < m['F']) answer += 'F';
	else answer += 'C';
	if (m['J'] < m['M']) answer += 'M';
	else answer += 'J';
	if (m['A'] < m['N']) answer += 'N';
	else answer += 'A';
	return answer;
}