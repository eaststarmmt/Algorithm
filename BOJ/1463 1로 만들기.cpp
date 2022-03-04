#include<stdio.h>
#include<algorithm>
using namespace std;

int d[1000001];

int main() {
	int n;
	scanf("%d", &n);
	d[2] = 1;
	d[3] = 1;
	for (int i = 4; i <= n; i++) {
		d[i] = d[i - 1] + 1;	// -1�� ���� ó���ؾ� �ٸ� ����� �ּڰ� �񱳰� ����. �̰� ������ �Ǵ� ���� ������ ����� ó���ؼ� ������ ���� ���ϱ�
		if (i % 2 == 0)			// 2�� ���������� �� ������ �·� �ٲٱ�
			d[i] = min(d[i], d[i / 2] + 1);
		
		if (i % 3 == 0) {		// ���� ��������
			d[i] = min(d[i], d[i / 3] + 1);
		}
	}

	printf("%d\n", d[n]);
}