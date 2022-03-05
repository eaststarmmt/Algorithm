#include<cstdio>
using namespace std;
int N, M;
int output[5];
bool visited[7];
void method1(int cnt) {
	if (cnt == N) {
		for (int i = 0; i < N; i++) {
			printf("%d ", output[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= 6; i++) {
		output[cnt] = i;
		method1(cnt + 1);
	}
}

void method2(int cnt, int start) {
	if (cnt == N) {
		for (int i = 0; i < N; i++) {
			printf("%d ", output[i]);
		}
		printf("\n");
		return;
	}

	for (int i = start; i <= 6; i++) {

		output[cnt] = i;
		method2(cnt + 1, i);

	}
}

void method3(int cnt) {
	if (cnt == N) {
		for (int i = 0; i < N; i++) {
			printf("%d ", output[i]);
		}
		printf("\n");
		return;
	}


	for (int i = 1; i <= 6; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		output[cnt] = i;
		method3(cnt + 1);
		visited[i] = false;
	}
}

int main() {
	
	scanf("%d %d", &N, &M);
	
	switch (M)
	{
	case 1:
		method1(0);
		break;
	case 2:
		method2(0, 1);
		break;
	case 3:
		method3(0);
		break;
	}
}