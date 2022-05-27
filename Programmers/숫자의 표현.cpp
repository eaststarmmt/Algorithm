#include <string>
#include <vector>
using namespace std;

int solution(int n) {
	int answer = 0;
	int sum = 0;
	// summation(cnt - 1) +  n / cnt = n 인 경우만 가능
	for (int cnt = 1; sum < n; cnt++) {
		if ((n - sum) % cnt == 0) {
			answer++;
		}
		sum += cnt;
	}
	return answer;
}