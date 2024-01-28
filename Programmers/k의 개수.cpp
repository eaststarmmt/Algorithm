#include <string>
#include <vector>

using namespace std;

int count(int num, int k) {
	int res = 0;
	while (num) {
		if (num % 10 == k) res++;
		num /= 10;
	}
	return res;
}

int solution(int i, int j, int k) {
	int answer = 0;
	for (int num = i; num <= j; num++) {
		answer += count(num, k);
	}
	return answer;
}