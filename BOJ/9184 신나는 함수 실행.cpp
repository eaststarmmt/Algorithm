#include<stdio.h>
using namespace std;

int d[21][21][21];
// ������ ���������� �� �־��� �����Ƿ� ���� �̹� �ִ°��� �ٷ� ������ �����ΰ� �ٲٱ⸸ �ϸ� �Ǵ� ����
int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	if (d[a][b][c] != 0) return d[a][b][c];		// ���� �̹� �ִ��� Ȯ��. �ִٸ� �ٷ� return
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