#include<cstdio>
using namespace std;

bool checked[9];
int N, M;

void comb(int cnt, int start) {
	if (cnt == M) {
		for (int i = 1; i <= N; i++) {
			if(checked[i])
				printf("%d ", i);
		}
		printf("\n");
	}

	for (int i = start; i <= N; i++) {
		if (checked[i]) continue;
		checked[i] = true;
		comb(cnt + 1, i + 1);
		checked[i] = false;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	comb(0, 1);
}