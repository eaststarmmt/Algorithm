#include<stdio.h>
//계산하다 보면 존나 커져서 long long 조차 감당 안될 수 있음
//미리미리 나눠서 저장할 것
int d[1000001];

int main() {
	int n;
	scanf("%d", &n);
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
		d[i] %= 15746;
	}
	printf("%d\n", d[n]);
}