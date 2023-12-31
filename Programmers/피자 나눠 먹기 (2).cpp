#include <string>
#include <vector>

using namespace std;

int gcm(int a, int b) {

	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int solution(int n) {
	int answer = 6 * n / gcm(6, n) / 6;
	return answer;
}