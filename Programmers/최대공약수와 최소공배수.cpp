#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int m) {
	vector<int> answer;
	int a = n;
	int b = m;
	int r;
	while (b != 0) {     // 유클리드 호제법으로 최대 공약수 구하기
		r = a % b;
		a = b;
		b = r;
	}

	answer = { a, n * m / a };
	return answer;
}