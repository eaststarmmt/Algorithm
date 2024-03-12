#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) {
	long long answer = 1;

	int len = balls - share < share ? balls - share : share;

	for (int i = 0; i < len; i++) {
		answer *= balls--;
		answer /= i + 1;
	}
	return answer;
}