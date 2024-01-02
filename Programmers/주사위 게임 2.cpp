#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c) {
	int answer = 0;
	int A = a + b + c;
	int B = a * a + b * b + c * c;
	int C = a * a * a + b * b * b + c * c * c;
	if (a != b && b != c && a != c) answer = A;
	else if (a == b && b == c) answer = A * B * C;
	else answer = A * B;
	return answer;
}