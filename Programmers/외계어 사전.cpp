#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<string> dictionry;

int solution(vector<string> spell, vector<string> dic) {
	int answer = 2;

	for (string temp : dic) {
		dictionry.insert(temp);
	}

	sort(spell.begin(), spell.end());

	do {
		string s;
		for (string temp : spell) {
			s += temp;
		}

		if (dictionry.find(s) != dictionry.end()) {
			answer = 1;
			break;
		}

	} while (next_permutation(spell.begin(), spell.end()));
	return answer;
}