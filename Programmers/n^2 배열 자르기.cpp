#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
	vector<int> answer;
	for (long long i = left; i <= right; i++) {
		long long min_val = i / n + 1;      // 몫 + 1 이 그 행의 minimum value임
		long long x = i % n + 1;            // max(나머지 + 1, 몫 + 1) 이 해당 인덱스의 값임
		answer.push_back(x < min_val ? min_val : x);
	}
	return answer;
}