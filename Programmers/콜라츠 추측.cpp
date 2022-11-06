#include <string>
#include <vector>

using namespace std;

int solution(int num) {
	int answer = -1;
	long long x = num;
	for (int i = 0; i <= 500; i++) {
		if (x == 1) return i;
		if (x % 2 == 0) {
			x /= 2;
		}
		else {
			x = x * 3 + 1;
		}
	}
	return answer;
}