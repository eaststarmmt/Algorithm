#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int a, int b) {
	int answer = 0;
	if (a % 2 == 1 && b % 2 == 1) answer = a * a + b * b;
	else if (a % 2 != b % 2) answer = 2 * (a + b);
	else answer = abs(a - b);
	return answer;
}