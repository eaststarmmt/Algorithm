#include<stdio.h>
using namespace std;

int C;

long long divideCon(int A, int B) {
	if (B == 0) return 1;		// 0���̸� 1 ���
	else if (B == 1) return A;	// 1���̸� A ���
	if (B % 2 != 0) return A * divideCon(A, B - 1); // Ȧ���� 2��� �ϱ� ���� ¦���� ������
	else {
		return (divideCon(A, B / 2) % C) * (divideCon(A, B / 2) % C) % C;	// ��� ������ �������� ��� ���� ���� �ȳѰ� ��� ����
	}
}

int main() {
	
	int A, B;
	scanf("%d %d %d", &A, &B, &C);
	printf("%lld",divideCon(A, B) % C);
}