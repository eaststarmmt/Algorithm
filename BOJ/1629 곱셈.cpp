#include<stdio.h>
using namespace std;

int C;

long long divideCon(int A, int B) {
	if (B == 0) return 1;		// 0승이면 1 출력
	else if (B == 1) return A;	// 1승이면 A 출력
	if (B % 2 != 0) return A * divideCon(A, B - 1); // 홀수면 2등분 하기 위해 짝수로 맞춰줌
	else {
		return (divideCon(A, B / 2) % C) * (divideCon(A, B / 2) % C) % C;	// 몇번 나누던 나머지는 계속 같음 범위 안넘게 계속 나눔
	}
}

int main() {
	
	int A, B;
	scanf("%d %d %d", &A, &B, &C);
	printf("%lld",divideCon(A, B) % C);
}