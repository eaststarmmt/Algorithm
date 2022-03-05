#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

long long A, B, result = -1;	// 탈출 조건을 따로 줄 방법을 못찾아서 끝까지 다 돌리기 위해 -1로 초기화

void bfs() {
	queue<pair<long long, int>> queue;
	queue.push({ A, 1 });
	while (!queue.empty()) {
		long long x = queue.front().first;
		int cnt = queue.front().second;
		if (x == B) {				// 같으면 탈출. 여길 안오면 -1로 출력
			result = cnt;
			return;
		}
		queue.pop();

		if (x * 2 <= B)							// 크면 의미가 없음. 어차피 작아지진 않음
			queue.push({ x * 2, cnt + 1 });
		if (x * 10 + 1 <= B)
			queue.push({ x * 10 + 1, cnt + 1 });
	}
}

int main() {

	scanf("%lld %lld", &A, &B);
	if (A == B) {
		printf("%d", 0);
		return 0;
	}
	bfs();
	printf("%d", result);
}