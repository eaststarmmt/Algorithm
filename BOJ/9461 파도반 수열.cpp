#include<stdio.h>
// 피보나치 수열의 개념. 점화식이 맞고 테스트케이스도 맞는데 틀리면
// 자료형 의심해볼것
long long d[100];

int main() {
	int t;
	scanf("%d", &t);
	d[1] = 1;
	d[2] = 1;
	for(int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		for (int j = 3; j <= n; j++) {
			d[j] = d[j - 3] + d[j - 2];
		}
		printf("%lld\n", d[n]);
	}
}