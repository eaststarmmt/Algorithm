#include <string>
#include <vector>
#include <sstream>
using namespace std;

int solution(string binomial) {
	int answer = 0;
	stringstream ss(binomial);
	string a, b, op;
	ss >> a;
	ss >> op;
	ss >> b;

	if (op == "+") answer = stoi(a) + stoi(b);
	else if (op == "-") answer = stoi(a) - stoi(b);
	else answer = stoi(a) * stoi(b);

	return answer;
}