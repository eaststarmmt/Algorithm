#include<stdio.h>
using namespace std;

int N, M;
int output[8];
bool checked[9];

void permu(int start, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", output[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!checked[i]) {
			output[cnt] = i;
			checked[i] = true;
			permu(i + 1, cnt + 1);
			checked[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	permu(1, 0);
}