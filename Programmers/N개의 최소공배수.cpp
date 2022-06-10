#include <string>
#include <vector>

using namespace std;

int getGcd(int r1, int r2) {    // 유클리드 호제법
	int r;
	while (r2 > 0) {
		int q = r1 / r2;
		r = r1 - q * r2;
		r1 = r2;
		r2 = r;
	}
	return r1;
}

int solution(vector<int> arr) {
	int answer = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		int gcd = getGcd(answer, arr[i]);
		answer = arr[i] * answer / gcd;     // A / gcd * b / gcd * gcd = lcm
	}
	return answer;
}