#include<cstdio>
#include<algorithm>
using namespace std;

int d[1001];
int num[1001];
int main() {
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		int N;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &num[i]);
		}
		int result = 1;
		for (int i = 1; i <= N; i++) {
			d[i] = 1;
			for (int j = 1; j <= i - 1; j++) {
				if (num[i] > num[j]) {
					d[i] = max(d[i], d[j] + 1);
					result = d[i] > result ? d[i] : result;
				}
			}
		}
		printf("#%d %d\n", test, result);
	}
}