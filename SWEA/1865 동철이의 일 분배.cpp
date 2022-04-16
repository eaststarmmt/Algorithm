#include<cstdio>
#include<cstring>
using namespace std;

bool selected[17];
double work[17][17];
int N;
double workTime[17];
double result;
void comb(double total, int start, int cnt) {
	if (cnt == N + 1) {
		result = total > result ? total : result;
	}
	if (total <= result) return;		// 곱할수록 작아지므로 이미 작거나 같으면 할 필요가 없음
	for (int i = 1; i <= N; i++) {		// 일은 하나씩 맡으므로 1번부터 계속 확인
		if (selected[i]) continue;		// 이미 선택된 일은 할 필요 없음
		selected[i] = true;
		comb(total * work[cnt][i],start + 1, cnt + 1);	
		selected[i] = false;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		scanf("%d", &N);
		result = 0;
		memset(selected, false, sizeof(selected));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				double x;
				scanf("%lf", &x);
				work[i][j] = x / 100;
			}
		}

		comb(1, 1, 1);
		printf("#%d %.6lf\n", test, result * 100);	// printf 소수점 지정하면 자동으로 반올림 해서 나옴
	}
}