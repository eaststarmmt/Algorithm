#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	int r;

	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int check(int gcd, vector<int>& array) {
	for (int x : array) {
		if (x % gcd == 0) return 0;
	}

	return gcd;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
	int answer = 0;

	int gcd_a = arrayA[0];
	for (int i = 1; i < arrayA.size(); i++) {
		gcd_a = gcd(gcd_a, arrayA[i]);
	}   // end of for

	int gcd_b = arrayB[0];
	for (int i = 1; i < arrayB.size(); i++) {
		gcd_b = gcd(gcd_b, arrayB[i]);
	}   // end of for

	answer = max(answer, check(gcd_a, arrayB));
	answer = max(answer, check(gcd_b, arrayA));
	return answer;
}