#include<cstdio>
#include<vector>
#include<climits>
#define MAX 10000001
using namespace std;

bool composite[MAX];
int main() {
	long long A, B;
	scanf("%lld %lld", &A, &B);
	vector<long long> prime;
	for (long long i = 2; i < MAX; i++) {
		if (composite[i]) continue;
		prime.push_back(i);			// 소수만 따로 저장
		for (long long j = i * 2; j < MAX; j += i) {
			composite[j] = true;
		}
	}		// end of for composite

	long long res = 0;
	for (auto i : prime) {	// size를 long long 형으로 사용할 수 없어서 for each로 접근
		long long now = i;
		for (long long j = now * now; j <= B; j *= now) {
			if (j < A) continue;
			res++;
			if (LLONG_MAX / now < j) break;		// overflow로 인한 값이 틀려지는 현상 막기 위함
		}
	}
	printf("%lld\n", res);
}