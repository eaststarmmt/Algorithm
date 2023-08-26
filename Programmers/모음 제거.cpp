#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<char> a = { 'a', 'e', 'i', 'o', 'u' };

string solution(string my_string) {
	string answer = "";
	for (char c : my_string) {
		if (find(a.begin(), a.end(), c) != a.end()) continue;
		answer += c;
	}   // end of for 
	return answer;
}