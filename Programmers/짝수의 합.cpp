#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	for (int i = 0; i <= n; i++) {
		if (i % 2 == 1) continue;
		answer += i;
	}
	return answer;
}