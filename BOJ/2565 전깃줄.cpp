#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 501		// �迭�� 100���� ��������� A�� 500������ ���ͼ� 500�� ���. �׳� pair�Ἥ sort�ϴ°� �������� ������ ����

int main() {

	int n;
	scanf("%d", &n);

	int line[MAX] = { 0 };		// 0 �ΰ�� �ɷ��� �Ǳ� ������ �ΰ� �� 0���� �ʱ�ȭ 
	int dp[MAX] = { 0 };


	int last = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		line[x] = y;			// A�� x��° �����ٿ��� B�� y��° ������. �ٵ� pair ���°� ������
		last = max(last, x);	// �߰��� ��°� �־ �迭�� ������ ������ �ڿ��� Ȯ���� ����
	}

	int result = 0;

	for (int i = 1; i <= last; i++) {
		if (line[i] == 0) continue;		// �� ���µ� ���� dp�� 1 �־������ LIS ����ϴ� �������� 1�� �� ����
		dp[i] = 1;

		for (int j = 1; j < i; j++) {
			if (line[i] > line[j]) {
				dp[i] = max(dp[i], dp[j] + 1);		// j ���� ũ�ٴ� ���� j������ LIS���� ������ 1�� �� ũ�ٴ� �Ҹ�
			}
		}
		result = max(dp[i], result);		// ���ݱ��� ���� LIS ���� �� �ִ밪 ��������
	}

	printf("%d", n - result);				// ��ü �� �������� LIS ���ָ� ������ �Ǵ� �� ���� ����
}