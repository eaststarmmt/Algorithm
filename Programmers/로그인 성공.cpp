#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
	string answer = "";
	map<string, string> m;

	for (int i = 0; i < db.size(); i++) {
		m.insert({ db[i][0], db[i][1] });
	}

	auto it = m.find(id_pw[0]);
	if (it == m.end()) answer = "fail";
	else if (m[id_pw[0]] == id_pw[1]) answer = "login";
	else answer = "wrong pw";
	return answer;
}