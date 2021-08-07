// ������ �𸣰����� �޸� �ʰ��� ����ؼ� �߻��߰� if���� ������ �ٲٴ� ����ó��
// �ٽ� �޸��ʰ����� ������ ���ȴµ� ����

#include<stdio.h>
#include<queue>
#define MAX 100001
using namespace std;

bool visited[MAX];					// �湮�� �� üũ ���ϸ� ť�� �ʹ� ���� ���ͼ� �����ϱ� ����

int bfs(int start, int end) {

	queue<pair<int, int>> queue;
	queue.push({ start, 0 });
	visited[start] = true;			

	while (!queue.empty()) {

		int pos = queue.front().first;
		int sec = queue.front().second;
		queue.pop();

		if (pos == end) return sec;						// ���� ��ġ�� ���������� ������ �� ���� ����

		if ((pos + 1 < MAX) && !visited[pos + 1]) {		// ������ �̵��ϴ� ���
			queue.push({ pos + 1, sec + 1 });			// �湮���� ���� ������ ����� ������ �湮
			visited[pos + 1] = true;
		}

		if ((0 <= pos - 1) && !visited[pos - 1]) {		// �ڷ� �̵��ϴ� ���
			queue.push({ pos - 1, sec + 1 });			// �湮���� ���� ������ ����� ������ �湮
			visited[pos - 1] = true;
		}
			
		if ((pos * 2 < MAX) && !visited[pos * 2]) {		// �����̵� �ϴ� ���
			queue.push({ pos * 2, sec + 1 });			// �湮���� ���� ������ ����� ������ �湮
			visited[pos * 2] = true;
		}
	}
}

int main() {
	
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d\n",bfs(N, K));
}