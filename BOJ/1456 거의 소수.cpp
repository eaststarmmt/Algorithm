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
		prime.push_back(i);			// �Ҽ��� ���� ����
		for (long long j = i * 2; j < MAX; j += i) {
			composite[j] = true;
		}
	}		// end of for composite

	long long res = 0;
	for (auto i : prime) {	// size�� long long ������ ����� �� ��� for each�� ����
		long long now = i;
		for (long long j = now * now; j <= B; j *= now) {
			if (j < A) continue;
			res++;
			if (LLONG_MAX / now < j) break;		// overflow�� ���� ���� Ʋ������ ���� ���� ����
		}
	}
	printf("%lld\n", res);
}