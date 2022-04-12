#include<stdio.h>
using namespace std;

int graph[101][101];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	for (int k = 1; k <= n; k++) {	//이미 경로는 다 주어짐.거쳐서 갈수 있는지 여부만 판단하면 됨
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				if (graph[a][k] && graph[k][b]) graph[a][b] = 1;
			}
		}
	}
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			printf("%d ", graph[a][b]);
		}
		printf("\n");
	}
}