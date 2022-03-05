#include<cstdio>
#include<algorithm>
#define MAX 101		// 간선 최대 개수
#define INF 1e9
using namespace std;

int d[MAX][MAX];

int main() {
	int V, E;
	scanf("%d %d", &V, &E);

	for (int i = 1; i <= V; i++) {
		fill(d[i], d[i] + V + 1, INF);	// 배열의 값을 INF로 초기화
	}

	for (int i = 1; i <= V; i++) {
		d[i][i] = 0;		// 자기 자신은 0
	}

	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		d[a][b] = c < d[a][b] ? c : d[a][b];	// a에서 b로 가는 cost = c. 여기서는 여러개 입력 되므로 최소값 넣기
	}

	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);	// 기존 i에서 j 가는 방법과 k 거쳐서 가는 방법 비교
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