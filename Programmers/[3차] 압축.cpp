#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string, int> map;

void init() {
	for (char i = 'A'; i <= 'Z'; i++) {
		string s;
		s += i;
		map.insert({ s, i - 'A' + 1 });
	}
}

int findDic(int& start, string& msg) {
	string target = msg.substr(start, 1); // 무조건 한 글자는 들어있음
	int i;
	for (i = start + 1; i < msg.size(); i++) {
		target += msg[i];
		if (map.find(target) == map.end()) {
			map.insert({ target, map.size() + 1 });
			start = i - 1;
			return map[target.substr(0, target.size() - 1)];
		}
	}
	start = i;              // 끝나고 더 진행하는것을 막기 위해 어디까지 했는지 넘겨줌
	return map[target];     // 마지막 글자
}

vector<int> solution(string msg) {
	vector<int> answer;
	init();
	for (int i = 0; i < msg.size(); i++) {
		answer.push_back(findDic(i, msg));
	}   // end of for
	return answer;
}