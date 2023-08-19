#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) {
	int answer = 0;
	for (int i = 0; i <= 50; i++) {
		if (i * slice >= n) {
			answer = i;
			break;
		}
	}
	return answer;
}