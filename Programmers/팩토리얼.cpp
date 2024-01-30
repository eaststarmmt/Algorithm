#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 1;
	for (int i = 1, fact = 1; i <= 10; i++) {
		fact *= i;
		if (fact > n) {
			answer = i - 1;
			break;
		}
		answer = i;
	}
	return answer;
}