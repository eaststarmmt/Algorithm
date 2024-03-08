#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string a, string b) {
	string answer = "";

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	if (a.size() > b.size()) b.resize(a.size(), '0');
	else a.resize(b.size(), '0');

	int carry = 0;

	for (int i = 0; i < a.size(); i++) {
		int sum = (a[i] - '0') + (b[i] - '0') + carry;
		answer += (sum % 10) + '0';
		carry = sum / 10;
	}
	if (carry != 0) answer += carry + '0';
	reverse(answer.begin(), answer.end());

	return answer;
}