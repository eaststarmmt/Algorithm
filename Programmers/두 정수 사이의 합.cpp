#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int a, int b) {
	long long answer = 0;
	long long min_num = min(a, b);
	long long max_num = max(a, b);

	for (long long i = min_num; i <= max_num; i++) {
		answer += i;
	}
	return answer;
}