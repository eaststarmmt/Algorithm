#include <string>
#include <vector>
#include <cmath>
using namespace std;

int getBlock(int x) {
	if (x == 1) return 0;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0 && x / i <= 10000000) {
			return x / i;           // 낮은수부터 가장 먼저 나오는 몫이 최대 값임
		}
	}
	return 1;
}

vector<int> solution(long long begin, long long end) {
	vector<int> answer;
	for (int i = begin; i <= end; i++) {
		answer.push_back(getBlock(i));
	}

	return answer;
}