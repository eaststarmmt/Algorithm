#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> m;

vector<string> solution(vector<string> players, vector<string> callings) {
	vector<string> answer(players.begin(), players.end());

	for (int i = 0; i < players.size(); i++) {
		m[players[i]] = i;
	}

	for (string s : callings) {
		int idx = m[s];
		swap(m[answer[idx]], m[answer[idx - 1]]);
		swap(answer[idx], answer[idx - 1]);

	}   // end of for
	return answer;
}