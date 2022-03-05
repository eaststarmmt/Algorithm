#include<cstdio>
using namespace std;

int map[2001][2001];
int now[2000];
int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int bird = 1; bird <= N; bird++) {	// ���� 1����
		char s;
		scanf(" %c", &s);
		for (int i = 0; i < M; i++) {	// �ð��� 0����
			int x;
			scanf("%1d", &x);
			if (s == 'L')
				map[bird][i] = -x;
			else
				map[bird][i] = x;
		}
	}	// end of input
	
	// ���� �� ���̺� �����
	for (int bird = 1; bird <= N; bird++) {
		now[0] += map[bird][0];
	}
	for (int i = 1; i < M; i++) {
		now[i] = now[i - 1];	// ������ �����ΰſ��� ������
		for (int bird = 1; bird <= N; bird++) {
			now[i] += map[bird][i];
		}
	}	// end of now

	int kill = 1;
	int ans = 1e9;

	for (int bird = 1; bird <= N; bird++) {	// �� �Ѹ����� �����ϸ鼭 ��� ã��
		int min = 0;
		int max = 0;
		int noBird = 0;	// �ش� �� ���� ��� ��
		int sum = 0;	// ������ ���� ���ݱ��� ���� ��� �� ����
		for (int i = 0; i < M; i++) {	// �������� ������� ���� �Ѵ� ������. TLE ���� ����
			sum += map[bird][i];
			noBird = now[i] - sum;		// ���� ���� �̵��� ������ ������ ������ ���ָ� ��Ȯ�� ���� ��찡 ����
			min = noBird < min ? noBird : min;
			max = noBird > max ? noBird : max;
		}
		int tot = max > -min ? max : -min;
		if (ans > tot) {
			ans = tot;
			kill = bird;
		}
	}
	printf("%d\n%d\n", kill, ans);
}