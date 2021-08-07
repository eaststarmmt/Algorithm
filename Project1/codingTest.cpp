// 이유는 모르겠으나 메모리 초과가 계속해서 발생했고 if문의 순서를 바꾸니 정답처리
// 다시 메모리초과때의 순서로 돌렸는데 정답

#include<stdio.h>
#include<queue>
#define MAX 100001
using namespace std;

bool visited[MAX];					// 방문한 곳 체크 안하면 큐에 너무 많이 들어와서 감당하기 힘듬

int bfs(int start, int end) {

	queue<pair<int, int>> queue;
	queue.push({ start, 0 });
	visited[start] = true;			

	while (!queue.empty()) {

		int pos = queue.front().first;
		int sec = queue.front().second;
		queue.pop();

		if (pos == end) return sec;						// 현재 위치가 도착지점과 같으면 초 값을 리턴

		if ((pos + 1 < MAX) && !visited[pos + 1]) {		// 앞으로 이동하는 경우
			queue.push({ pos + 1, sec + 1 });			// 방문한적 없고 범위를 벗어나지 않으면 방문
			visited[pos + 1] = true;
		}

		if ((0 <= pos - 1) && !visited[pos - 1]) {		// 뒤로 이동하는 경우
			queue.push({ pos - 1, sec + 1 });			// 방문한적 없고 범위를 벗어나지 않으면 방문
			visited[pos - 1] = true;
		}
			
		if ((pos * 2 < MAX) && !visited[pos * 2]) {		// 순간이동 하는 경우
			queue.push({ pos * 2, sec + 1 });			// 방문한적 없고 범위를 벗어나지 않으면 방문
			visited[pos * 2] = true;
		}
	}
}

int main() {
	
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d\n",bfs(N, K));
}