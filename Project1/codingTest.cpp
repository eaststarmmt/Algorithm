#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

bool breakDown[100001];

int main() {
	int N, K, B;
	scanf("%d %d %d", &N, &K, &B);
	for (int i = 1; i <= B; i++) {
		int x;
		scanf("%d", &x);
		breakDown[x] = true;		// 초기화 문제상 true가 고장난걸로. x번 신호등 고장
	}
	int result = 0;
	for (int i = 1; i <= K; i++) {
		if (!breakDown[i]) result++;	// 1 ~ K번 사이에 고장나지 않은 신호등 개수 저장
	}
	
	int cnt = result;

	if (N == K) {			// 원형이 아니라 N과 K가 같으면 무한루프 돌아서 예외처리
		printf("%d\n", K - result);
		return 0;
	}

	int start = K + 1;	// K + 1번부터 확인
	while (true) {
		if (!breakDown[start - K]) cnt--;	// 이전에 가장 앞에 신호등이 켜져있었으면 빼주기
		if (!breakDown[start]) cnt++;		// 현재 보는 신호등이 켜져 있으면 더하기
		result = cnt > result ? cnt : result;	// 신호등이 가장 많이 켜진 경우 계산
		start++;							// 다음번 인덱스 확인
		if (start == N + 1) break;			// N 을 넘어가면 범위 벗어나므로 탈출
	}
	printf("%d\n", K - result);
}