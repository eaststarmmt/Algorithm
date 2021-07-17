// 난이도가 높은 문제는 아닌데 값 바뀌고 출력되는 시점 신경 써야됨
// 타입도 int 쓰면 틀림. 주의할 것
#include<stdio.h>

int main() {
	long long now = 1;
	long long cnt = 0;
	long long n;
	scanf("%lld", &n);
	
	for (long long i = 1; i <= n; i++) {		
		if (cnt == now + 1) {
			now++;
			cnt = 0;
		}
		cnt++;
	}
	printf("%lld\n", now);
}