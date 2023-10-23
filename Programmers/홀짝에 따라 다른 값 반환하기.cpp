#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	for (int i = 0; i <= n; i++) {
		if (n % 2 && i % 2) answer += i;
		else if (n % 2 == i % 2) answer += i * i;
	}
	return answer;
}