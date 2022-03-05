#include<cstdio>
#define MAX 100001
using namespace std;

int train[MAX];
bool value[1 << 20];	// ��� ����� Ÿ ������� 2^21 - 1 �̹Ƿ� 2 ^ 21 ũ��� ����

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b, c;				// a: ��� b: ������ȣ c: �¼���ȣ
		scanf("%d %d", &a, &b);
		if (a <= 2) {				// 1 2�� ���
			scanf("%d", &c);
			if(a == 1)
				train[b] |=(1 << c - 1);	// ex 2�� �¼��� �������� 1�� (2 - 1)��ŭ shift�ؾ� 2�� �¼� �ڸ��� �� ��. �׸��� or �������� �ִ� ���� �� �ڸ��� 1�� ����
			else
				train[b] &= ~(1 << c - 1);	// �������� �ڸ��� 0���� ����� and ������ ���� �� �ڸ��� 0���� ����
		}
		else {
			if (a == 3) {
				train[b] <<= 1;			// �������� shift ����
				train[b] &= (1 << 20) - 1;	// 2^21 -1 �� and ������ �Ͽ� 21��° �ڸ��� 0���� ����. 21��° �ڸ��� �����ϰ� �� 1�̹Ƿ� ������ ���
			}
			else {
				train[b] >>= 1;		// ���������� �и� ��� 1��° ���ϴ� ������
			}
		}
	}
	int ans = 1;
	value[train[1]] = true;			// 1�������� �� ǥ��
	for (int i = 2; i <= N; i++) {
		if (value[train[i]]) continue;	// �ش� ������ ���� ���� ��� �ǳ� ��
		value[train[i]] = true;		// ���� ��� ������ ǥ���ϰ� ī����
		ans++;
	}
	printf("%d\n", ans);
}