#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
string mos[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };

string solution(string letter) {
	string answer = "";
	map<string, char> m;

	for (int i = 0; i < 26; i++) {
		m[mos[i]] = 'a' + i;
	}

	stringstream ss(letter);
	string s;
	while (ss >> s) {
		answer += m[s];
	}

	return answer;
}