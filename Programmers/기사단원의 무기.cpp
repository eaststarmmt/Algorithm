#include <string>
#include <vector>

using namespace std;

int divisor[100004];

int solution(int number, int limit, int power) {
	int answer = 0;
	for (int i = 1; i <= number; i++) {  // divisor
		divisor[i]++;
		for (int j = i * 2; j <= number; j += i) {
			divisor[j]++;
		}
	}

	for (int i = 1; i <= number; i++) {
		answer += divisor[i] <= limit ? divisor[i] : power;
	}

	return answer;
}