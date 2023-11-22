#include <string>
#include <vector>

using namespace std;

int a[] = { 5, 3, 1 };

int solution(int hp) {
	int answer = 0;
	for (int i = 0; i < 3; i++) {
		answer += hp / a[i];
		hp %= a[i];
	}
	return answer;
}