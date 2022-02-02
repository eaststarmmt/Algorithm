#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

struct Grit {
	int a, b, c;
};

bool visited[1501][1501];	// ��� ���� �������� �����Ǵ� �־��� ��Ȳ�� 1500��. �տ� �ΰ��� ���ϸ� ������ ���ڴ� ������ ������ �ִٴ� �������� ����

void bfs(Grit grit) {
	queue<Grit> Q;
	Q.push(grit);
	visited[grit.a][grit.b] = true;	// ���� ���� �� �ڰ� ū ��
	visited[grit.a][grit.c] = true;
	visited[grit.b][grit.c] = true;
	int ngrit[3] = { 0 };	// �׳� sort�� �̰� �Ⱦ��� ��� �˸� �� �������ּ���....

	while (!Q.empty()) {
		Grit g = Q.front();
		Q.pop();
		if (g.a == g.b && g.a == g.c) {	// ��� ������ �ű⼭ ����
			printf("1\n");
			return;
		}
		
		if (g.a != g.b) {	// a b �ٸ����
			ngrit[2] = g.c;
			if (g.a > g.b) {
				ngrit[0] = g.a - g.b;
				ngrit[1] = g.b * 2;
			}
			else {
				ngrit[0] = g.a * 2;
				ngrit[1] = g.b - g.a;
			}
			sort(ngrit, ngrit + 3);	// �� �� �ۿ� ��� sort �����
			if (!visited[ngrit[0]][ngrit[1]]) {	// �湮�� �� ���� ����
				Q.push({ ngrit[0], ngrit[1], ngrit[2] });
				visited[ngrit[0]][ngrit[1]] = true;
			}
		}

		if (g.a != g.c) {	// a c �ٸ����
			ngrit[1] = g.b;
			if (g.a > g.c) {
				ngrit[0] = g.a - g.c;
				ngrit[2] = g.c * 2;
			}
			else {
				ngrit[0] = g.a * 2;
				ngrit[2] = g.c - g.a;
			}
			sort(ngrit, ngrit + 3);	// �� �� �ۿ� ��� sort �����
			if (!visited[ngrit[0]][ngrit[1]]) {	// �湮�� �� ���� ����
				Q.push({ ngrit[0], ngrit[1], ngrit[2] });
				visited[ngrit[0]][ngrit[1]] = true;
			}
		}

		if (g.b != g.c) {	// b c �ٸ����
			ngrit[0] = g.a;
			if (g.b > g.c) {
				ngrit[1] = g.b - g.c;
				ngrit[2] = g.c * 2;
			}
			else {
				ngrit[1] = g.b * 2;
				ngrit[2] = g.c - g.b;
			}
			sort(ngrit, ngrit + 3);	// �� �� �ۿ� ��� sort �����
			if (!visited[ngrit[0]][ngrit[1]]) {	// �湮�� �� ���� ����
				Q.push({ ngrit[0], ngrit[1], ngrit[2] });
				visited[ngrit[0]][ngrit[1]] = true;
			}
		}
	}
	printf("0\n");
}

int main() {
	int input[3];
	scanf("%d %d %d", &input[0], &input[1], &input[2]);
	sort(input, input + 3);
	Grit grit = { input[0], input[1], input[2] };
	bfs(grit);
}