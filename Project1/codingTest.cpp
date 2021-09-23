#include<cstdio>
#include<algorithm>
#define MAX 101		// ���� �ִ� ����
#define INF 1e9
using namespace std;

int d[MAX][MAX];

int main() {
	int V, E;
	scanf("%d %d", &V, &E);

	for (int i = 1; i <= V; i++) {
		fill(d[i], d[i] + V + 1, INF);	// �迭�� ���� INF�� �ʱ�ȭ
	}

	for (int i = 1; i <= V; i++) {
		d[i][i] = 0;		// �ڱ� �ڽ��� 0
	}

	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		d[a][b] = c < d[a][b] ? c : d[a][b];	// a���� b�� ���� cost = c. ���⼭�� ������ �Է� �ǹǷ� �ּҰ� �ֱ�
	}

	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);	// ���� i���� j ���� ����� k ���ļ� ���� ��� ��
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (d[i][j] == INF) printf("0 ");
			else printf("%d ", d[i][j]);
		}
		printf("\n");
	}
}