// ���̵��� ���� ������ �ƴѵ� �� �ٲ�� ��µǴ� ���� �Ű� ��ߵ�
// Ÿ�Ե� int ���� Ʋ��. ������ ��
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