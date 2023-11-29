#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector<int> solution(string myString) {
	vector<int> answer;
	stringstream ss(myString);
	string s;
	while (getline(ss, s, 'x')) {
		answer.push_back(s.size());
	}

	if (myString[myString.size() - 1] == 'x') answer.push_back(0);
	return answer;
}