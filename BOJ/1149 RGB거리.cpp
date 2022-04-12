#include<stdio.h>
#include<algorithm>
using namespace std;

int d[1001][3]; //각각 색별로 최솟값 받아놔야됨. 참조할 이전 값이 계속 바뀌는 문제
int color[3];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++)
			scanf("%d", &color[j]);
		for (int j = 0; j < 3; j++) { // 이전 값들 중 최솟값과 현재 들어온 값을 더함.
			d[i][j] = min(d[i - 1][(j + 1) % 3], d[i - 1][(j + 2) % 3]) + color[j];
		}
	}
	printf("%d\n", min(d[n][0], min(d[n][1], d[n][2])));
}