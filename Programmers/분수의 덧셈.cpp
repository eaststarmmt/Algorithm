#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
	vector<int> answer;

	int denom = denom1 * denom2 / gcd(denom1, denom2);
	numer1 *= denom / denom1;
	numer2 *= denom / denom2;
	int numer = numer1 + numer2;

	for (int i = 2; i <= min(denom, numer); i++) {
		while (numer % i == 0 && denom % i == 0) {
			numer /= i;
			denom /= i;
		}
	}

	answer = { numer, denom };
	return answer;
}