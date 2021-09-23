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

	if (K == N) {	// K가 N과 같으면 정렬하지 않은 상태이므로 바로 출력
		for (int i = 1; i <= N; i++) {
			printf("%d ", chicken[i]);
		}

		printf("\n");
		return 0;
	}

	for (int work = N / 2; work > 0; work /= 2) {	// work 현재 일하는 사람 수
		for (int i = 1; i <= N; i += N / work) {	// index를 (N / 일하는 사람 수) 만큼 묶어서 정렬
			sort(chicken + i, chicken + i + N / work);	// 일하는 사람 수 * 정렬할 치킨의 개수 = N
		}
		if (K == work) break;		// work명으로 정렬을 끝낸 후 루프 탈출
	}

	for (int i = 1; i <= N; i++) {
		printf("%d ", chicken[i]);
	}

	printf("\n");
}