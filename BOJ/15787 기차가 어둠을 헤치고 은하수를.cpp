#include<cstdio>
#define MAX 100001
using namespace std;

int train[MAX];
bool value[1 << 20];	// 모든 사람이 타 있을경우 2^21 - 1 이므로 2 ^ 21 크기로 선언

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b, c;				// a: 명령 b: 기차번호 c: 좌석번호
		scanf("%d %d", &a, &b);
		if (a <= 2) {				// 1 2번 명령
			scanf("%d", &c);
			if(a == 1)
				train[b] |=(1 << c - 1);	// ex 2번 좌석에 앉으려면 1을 (2 - 1)만큼 shift해야 2번 좌석 자리에 쏙 들어감. 그리고 or 연산으로 있던 없던 그 자리를 1로 만듬
			else
				train[b] &= ~(1 << c - 1);	// 앉으려는 자리만 0으로 만들고 and 연산을 통해 그 자리만 0으로 만듬
		}
		else {
			if (a == 3) {
				train[b] <<= 1;			// 왼쪽으로 shift 연산
				train[b] &= (1 << 20) - 1;	// 2^21 -1 과 and 연산을 하여 21번째 자리만 0으로 만듬. 21번째 자리를 제외하고 다 1이므로 가능한 방법
			}
			else {
				train[b] >>= 1;		// 오른쪽으로 밀릴 경우 1번째 이하는 버려짐
			}
		}
	}
	int ans = 1;
	value[train[1]] = true;			// 1번기차의 값 표시
	for (int i = 2; i <= N; i++) {
		if (value[train[i]]) continue;	// 해당 기차의 값이 있을 경우 건너 뜀
		value[train[i]] = true;		// 없는 경우 있음을 표시하고 카운팅
		ans++;
	}
	printf("%d\n", ans);
}