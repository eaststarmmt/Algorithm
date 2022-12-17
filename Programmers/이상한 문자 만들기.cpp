#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
	string answer = "";

	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; i < s.size(); j++, i++) {
			if (s[i] == ' ') {
				answer += s[i];
				break;
			}
			answer += j % 2 ? tolower(s[i]) : toupper(s[i]);
		}

	}
	return answer;
}