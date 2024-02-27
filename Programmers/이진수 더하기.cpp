#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int binary_to_decimal(string s) {
	reverse(s.begin(), s.end());
	int res = 0;
	for (int i = 0, bit = 1; i < s.size(); bit <<= 1, i++) {
		res += (s[i] - '0') * bit;
	}
	return res;
}

string decimal_to_binary(int x) {
	if (x == 0) return "0";
	string s;
	while (x) {
		s += x % 2 ? '1' : '0';
		x >>= 1;
	}
	reverse(s.begin(), s.end());
	return s;
}

string solution(string bin1, string bin2) {
	string answer = "";
	int res = binary_to_decimal(bin1) + binary_to_decimal(bin2);
	answer = decimal_to_binary(res);

	return answer;
}