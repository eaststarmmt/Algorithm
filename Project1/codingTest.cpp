#include<stdio.h>
using namespace std;

int main() {
	int cnt = 1;
	while (1) {
		int l, p, v;
		scanf("%d %d %d", &l, &p, &v);
		if (l == 0 && p == 0 && v == 0) break;		// ��� 0 ������ ����
		int sum = v / p * l;						// �� �ϼ� / ���� ���� * ��밡���� ��
		int surplus = v % p > l ? l : v % p;		// �������� ��밡���� ������ ũ�� l �ƴϸ� ������ 
		sum += surplus;
		printf("Case %d: %d\n", cnt, sum);
		cnt++;
	}
}