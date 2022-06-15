#include <string>
#include <vector>

using namespace std;

long long fact[201];

void setFact(int n) {
	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i <= n; i++) {
		fact[i] = fact[i - 1] * i;
	}
}

vector<int> solution(int n, long long k) {
	vector<int> answer;
	setFact(n);
	vector<int> num;
	for (int i = 1; i <= n; i++) {
		num.push_back(i);
	}
	for (int i = n; i >= 1; i--) {
		long long x = (k - 1) / fact[i - 1];    // num의 인덱스
		answer.push_back(num[x]);
		num.erase(num.begin() + x);       // 남은 숫자들로 다시 순서 잡기 위해 뺴줌
		k %= fact[i - 1];                 // n * (n - 1)! 의 구조 이므로 n -1의 나머지번째 숫자에서 다시 탐색하기 위함
		k = k == 0 ? fact[i - 1] : k;
	}
	return answer;
}