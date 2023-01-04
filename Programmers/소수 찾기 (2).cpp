#include <string>
#include <vector>

using namespace std;

bool a[1000004];

int solution(int n) {
	int answer = 0;
	for (int i = 2; i <= n / 2; i++) {
		for (int j = i * 2; j <= n; j += i) {
			a[j] = true;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (a[i]) continue;
		answer++;
	}
	return answer;
}