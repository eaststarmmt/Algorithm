#include <string>
#include <vector>

using namespace std;

int composit[104];

int solution(int n) {
	int answer = 0;
	for (int i = 2; i * i <= 100; i++) {
		if (composit[i]) continue;
		for (int j = i * 2; j <= 100; j += i) {
			composit[j] = 1;
		}
	}

	for (int i = 4; i <= n; i++) {
		if (composit[i]) answer++;
	}
	return answer;
}