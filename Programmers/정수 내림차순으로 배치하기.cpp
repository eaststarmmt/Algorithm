#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(char& a, char& b) {
	return a > b;
}

long long solution(long long n) {
	long long answer = 0;
	string num = to_string(n);
	sort(num.begin(), num.end(), cmp);
	answer = stol(num);
	return answer;
}