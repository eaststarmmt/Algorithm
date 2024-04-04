#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	return a % b ? gcd(b, a % b) : b;
}

int solution(int a, int b) {
	int answer = 0;

	b /= gcd(a, b);

	while (1) {
		if (b % 2 == 0) b /= 2;
		else if (b % 5 == 0) b /= 5;
		else break;
	}   // end of while

	answer = b == 1 ? 1 : 2;
	return answer;
}