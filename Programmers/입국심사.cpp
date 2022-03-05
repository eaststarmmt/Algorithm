#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// 시간을 타겟으로 잡아서 모든 심사관이 해당 시간 동안 심사할 수 있는 사람 수 세서 그 중 시간 최소값으로 뽑아내는 방법
long long binarySearch(int n, vector<int> times) {
	long long start = 1;
	long long end = (long long)n * (*max_element(times.begin(), times.end()));    // 최악의 경우
	long long res = end;
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long sum = 0;
		for (int i = 0; i < times.size(); i++) {
			sum += mid / times[i];  // 시간 / 심사하는데 걸리는 시간 = 해당 시간동안 심사할 수 있는 사람 수
		}   // end of sum
		if (sum >= n) {  // 검사를 모두 할 수 있는 경우. 이 중에 최소값 뽑아내야됨
			res = mid < res ? mid : res;
			end = mid - 1;
		}
		else {  // 시간이 모자란 경우. 시간 늘려줘야 됨
			start = mid + 1;
		}
	}
	return res;
}

long long solution(int n, vector<int> times) {
	long long answer = 0;
	answer = binarySearch(n, times);
	return answer;
}