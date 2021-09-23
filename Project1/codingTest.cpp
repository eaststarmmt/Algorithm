#include<cstdio>
#include<algorithm>
#define MAX 1048577
using namespace std;

int chicken[MAX];

int main() {
	int N;	
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int x;
		scanf("%d", &x);
		chicken[i] = x;
	}
	int K;
	scanf("%d", &K);

	if (K == N) {	// K�� N�� ������ �������� ���� �����̹Ƿ� �ٷ� ���
		for (int i = 1; i <= N; i++) {
			printf("%d ", chicken[i]);
		}

		printf("\n");
		return 0;
	}

	for (int work = N / 2; work > 0; work /= 2) {	// work ���� ���ϴ� ��� ��
		for (int i = 1; i <= N; i += N / work) {	// index�� (N / ���ϴ� ��� ��) ��ŭ ��� ����
			sort(chicken + i, chicken + i + N / work);	// ���ϴ� ��� �� * ������ ġŲ�� ���� = N
		}
		if (K == work) break;		// work������ ������ ���� �� ���� Ż��
	}

	for (int i = 1; i <= N; i++) {
		printf("%d ", chicken[i]);
	}

	printf("\n");
}