#include <iostream>
using namespace std;

bool eratos[4000001];
int prime[200000];
int sum, low, high, res;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 2; i <= N; i++) {
		if (eratos[i]) continue;
		for (int j = i * 2; j <= N; j += i) {
			eratos[j] = true;
		}	// end of for j
	}	// end of for i

	int prime_size = 0;	// 합성수 개수

	for (int i = 2; i <= N; i++) {
		if (!eratos[i]) {
			prime[prime_size++] = i;
		}
	}	// end of for i

	while (true) {	// 투포인터 알고리즘. prime 배열은 오름차순으로 소수가 들어있음	
		if (sum > N) {	// 빼는 로직이 우선으로 계산되어야 자기 자신이 소수 인 경우가 계산 됨
			sum -= prime[low++];
		}
		else if (prime_size == high) {	// 소수를 끝까지 봤으면 종료. prime은 prime_size - 1번까지 들어있음
			break;
		}
		else if (sum <= N) {
			sum += prime[high++];
		}
		
		if (sum == N) {
			res++;
		}
	}	// end of while

	cout << res << "\n";
	return 0;
}