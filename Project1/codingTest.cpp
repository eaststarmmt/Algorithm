#include<cstdio>
using namespace std;

int map[2001][2001];
int now[2000];
int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int bird = 1; bird <= N; bird++) {	// 새는 1부터
		char s;
		scanf(" %c", &s);
		for (int i = 0; i < M; i++) {	// 시간은 0부터
			int x;
			scanf("%1d", &x);
			if (s == 'L')
				map[bird][i] = -x;
			else
				map[bird][i] = x;
		}
	}	// end of input
	
	// 현재 값 테이블 만들기
	for (int bird = 1; bird <= N; bird++) {
		now[0] += map[bird][0];
	}
	for (int i = 1; i < M; i++) {
		now[i] = now[i - 1];	// 이전에 움직인거에서 누적임
		for (int bird = 1; bird <= N; bird++) {
			now[i] += map[bird][i];
		}
	}	// end of now

	int kill = 1;
	int ans = 1e9;

	for (int bird = 1; bird <= N; bird++) {	// 새 한마리씩 제외하면서 결과 찾기
		int min = 0;
		int max = 0;
		int noBird = 0;	// 해당 새 없는 경우 값
		int sum = 0;	// 없어진 새가 지금까지 영향 줬던 값 누적
		for (int i = 0; i < M; i++) {	// 음수일지 양수일지 몰라서 둘다 생각함. TLE 막기 위함
			sum += map[bird][i];
			noBird = now[i] - sum;		// 잡을 새가 이동한 누적을 기존의 값에서 빼주면 정확히 없는 경우가 나옴
			min = noBird < min ? noBird : min;
			max = noBird > max ? noBird : max;
		}
		int tot = max > -min ? max : -min;
		if (ans > tot) {
			ans = tot;
			kill = bird;
		}
	}
	printf("%d\n%d\n", kill, ans);
}