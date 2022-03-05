#include<stdio.h>
#include<algorithm>
using namespace std;

int durability[8];
int weight[8];
int result;
int N;

void permutation(int now, int broken) {
	
	result = max(result, broken);

	if (now == N) return;	// 끝까지 다 해본 경우

	for (int i = 0; i < N; i++) {	// now가 들고있는 계란, i가 맞을 계란

		if (i == now || durability[i] <= 0) continue;	// 현재 들고있는 계란하고 맞을 계란이 겹치거나 때리려는 계란이 깨져있으면 무시
		if (durability[now] <= 0) {						// 지금 잡은 계란이 깨져있으면 다음 계란을 잡으러 넘기고 종료
			permutation(now + 1, broken);
			return;
		}
		int cnt = 0;
		durability[i] -= weight[now];				// 계란이 깨진 경우 카운팅
		if (durability[i] <= 0) 
			cnt++;
		durability[now] -= weight[i];
		if (durability[now] <= 0) 
			cnt++;

		permutation(now + 1, broken + cnt);
		durability[i] += weight[now];				// 다음 순열 조회를 위해 돌려놓는다
		durability[now] += weight[i];
		
	}
}


int main() {
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &durability[i], &weight[i]);
	}

	permutation(0, 0);
	printf("%d", result);
}