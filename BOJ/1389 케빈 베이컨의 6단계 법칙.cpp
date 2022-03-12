#include<cstdio>
#include<algorithm>
#define INF 1e9
using namespace std;

int graph[101][101];
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		fill(graph[i], graph[i] + N + 1, INF);
	}
	for (int i = 1; i <= N; i++) {
		graph[i][i] = 0;
	}
	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}	// end of graph

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}	// end of floyd warshall
	int min_value = 1e9;
	int answer;
	for (int i = 1; i <= N; i++) {
		int kevin = 0;
		for (int j = 1; j <= N; j++) {
			kevin += graph[i][j];
		}
		if (min_value > kevin) {
			min_value = kevin;
			answer = i;
		}
	}
	printf("%d\n", answer);
}