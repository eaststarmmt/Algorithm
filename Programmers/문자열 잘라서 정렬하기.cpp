#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> solution(string myString) {
	vector<string> answer;
	stringstream ss(myString);
	string s;
	while (getline(ss, s, 'x')) {
		if (s == "") continue;
		answer.push_back(s);
	}

	sort(answer.begin(), answer.end());
	return answer;
}