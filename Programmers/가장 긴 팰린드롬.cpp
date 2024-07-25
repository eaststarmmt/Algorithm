#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int get_len(int lo, int hi, string s) {
	while (lo >= 0 && hi < s.size()) {
		if (s[lo] != s[hi]) break;
		lo--;
		hi++;
	}   // end of while

	return hi - lo - 1;
}

int solution(string s)
{
	int answer = 1;

	for (int i = 1; i < s.size(); i++) {
		answer = max(answer, get_len(i, i, s));
		answer = max(answer, get_len(i - 1, i, s));
	}   // end of for

	return answer;
}