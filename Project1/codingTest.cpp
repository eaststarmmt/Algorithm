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
	if (total <= result) return;		// ���Ҽ��� �۾����Ƿ� �̹� �۰ų� ������ �� �ʿ䰡 ����
	for (int i = 1; i <= N; i++) {		// ���� �ϳ��� �����Ƿ� 1������ ��� Ȯ��
		if (selected[i]) continue;		// �̹� ���õ� ���� �� �ʿ� ����
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
		printf("#%d %.6lf\n", test, result * 100);	// printf �Ҽ��� �����ϸ� �ڵ����� �ݿø� �ؼ� ����
	}
}