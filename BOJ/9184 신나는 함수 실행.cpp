#include<stdio.h>
using namespace std;

int d[21][21][21];
// 문제에 기저조건이 다 주어져 있으므로 값이 이미 있는것은 바로 꺼내서 쓰도로고 바꾸기만 하면 되는 문제
int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	if (d[a][b][c] != 0) return d[a][b][c];		// 값이 이미 있는지 확인. 있다면 바로 return
	if (a < b && b < c) return d[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else return d[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
	while (1) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) break;
		else printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}
}