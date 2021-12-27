#include<cstdio>
#define endl "\n"
using namespace std;

int dp[500][500][2];
int b[3];

int bead(int k1, int k2, int seq) {	// seq 1�̸� A���� 0�̸� B
	if (dp[k1][k2][seq] >= 0)	// 0 �̻��̸� �״�� ����
		return dp[k1][k2][seq];
	if(k1 == 0 && k2 == 0)		// �Ѵ� 0�̸� ������ ���� ������Ƿ� ���� ���ʰ� �����Ƿ� 0 ����
		return dp[k1][k2][seq] = 0;
	for (int i = 0; i < 3; i++) {
		if (b[i] <= k1 && !bead(k1 - b[i], k2, 1 - seq)) {	// ���� ������ ���� �̴� ������� ����, ���� ���ʰ� ������� �̱�
			return dp[k1][k2][seq] = 1;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (b[i] <= k2 && !bead(k1, k2 - b[i], 1 - seq)) {		
			return dp[k1][k2][seq] = 1;
		}
	}
	return 0;	// ������� ���� �ϳ��� �̱� �� �ִ� ����� ���� �� �������Ƿ� ����
}

int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < 500; i++) {			// ��� ���� ���� �� -1�� �ʱ�ȭ
		for (int j = 0; j < 500; j++) {
			dp[i][j][0] = -1;
			dp[i][j][1] = -1;
		}
	}
	for (int i = 0; i < 5; i++) {
		int k1, k2;
		scanf("%d %d", &k1, &k2);
		if (bead(k1, k2, 1))	// 1�� ������ A�� �̱�
			printf("A\n");
		else
			printf("B\n");
	}
}