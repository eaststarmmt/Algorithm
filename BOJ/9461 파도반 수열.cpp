#include<stdio.h>
// �Ǻ���ġ ������ ����. ��ȭ���� �°� �׽�Ʈ���̽��� �´µ� Ʋ����
// �ڷ��� �ǽ��غ���
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