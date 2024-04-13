#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> quiz) {
	vector<string> answer;

	for (string s : quiz) {
		stringstream stream(s);
		string temp;

		int a, b;
		b = 0;
		while (stream >> temp) {
			if (temp == "+") b = 1;
			else if (temp == "-") b = -1;
			else if (!b) a = stoi(temp);
			else if (b == 1) {
				a += stoi(temp);
				b = 2;
			}
			else if (temp == "=") continue;
			else if (b == -1) {
				a -= stoi(temp);
				b = 2;
			}
			else if (b == 2) {
				if (a == stoi(temp)) answer.push_back("O");
				else answer.push_back("X");
			}
		}


	}
	return answer;
}