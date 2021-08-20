#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

long long A, B, result = -1;	// Ż�� ������ ���� �� ����� ��ã�Ƽ� ������ �� ������ ���� -1�� �ʱ�ȭ

void bfs() {
	queue<pair<long long, int>> queue;
	queue.push({ A, 1 });
	while (!queue.empty()) {
		long long x = queue.front().first;
		int cnt = queue.front().second;
		if (x == B) {				// ������ Ż��. ���� �ȿ��� -1�� ���
			result = cnt;
			return;
		}
		queue.pop();

		if (x * 2 <= B)							// ũ�� �ǹ̰� ����. ������ �۾����� ����
			queue.push({ x * 2, cnt + 1 });
		if (x * 10 + 1 <= B)
			queue.push({ x * 10 + 1, cnt + 1 });
	}
}

int main() {

	scanf("%lld %lld", &A, &B);
	if (A == B) {
		printf("%d", 0);
		return 0;
	}
	bfs();
	printf("%d", result);
}