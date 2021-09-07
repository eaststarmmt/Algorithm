#include<cstdio>
#include<cmath>
using namespace std;

bool flag = true;

//int divideCon(int x) {
//	if (x == 1) {
//		return 0;
//	}
//	else if (x == 2) {
//		return 1;
//	}
//	if (x % 2 == 1) {
//		return divideCon(x / 2 + 1);
//	}
//	else {
//		return (divideCon(x / 2) + 1) % 2;
//	}
//}

int main() {
	long long k;
	scanf("%lld", &k);
	int index;
	int flag = 0;
	for (int i = 0;; i++) {
		long long x = pow(2, i);
		if (x == k) {
			printf("%d", i % 2);
			return 0;
		}
		if (x > k) {
			k -= pow(2, i - 1);
			break;
		}
	}
	while (1) {
		if (k == 1) {
			printf("%d", (1 + flag) % 2);
			break;
		}
		else if (k == 2) {
			printf("%d", (0 + flag) % 2);
			break;
		}
		if (k % 2 == 1) k = k / 2 + 1;
		else {
			k = k / 2;
			flag = (flag + 1) % 2;
		}
	}
	//printf("%d\n", divideCon(k));
}