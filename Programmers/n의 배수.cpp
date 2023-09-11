#include <string>
#include <vector>

using namespace std;

int solution(int num, int n) {
	int answer = num % n == 0 ? 1 : 0;
	return answer;
}