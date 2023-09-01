#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	while (n) {
		answer += n % 10;
		n /= 10;
	}
	return answer;
}