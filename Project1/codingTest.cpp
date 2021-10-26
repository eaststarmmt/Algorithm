#include<iostream>
#include<algorithm>
#define endl "\n"
#define INF 1e9
using namespace std;

int graph[101][101];
int counting[101];

void print(int N, int M) {	// 그냥 의미 없음 graph 상태 출력
	cout << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {	// 크다 작다 오로지 방향만을 넣어놓기
		int a, b;
		cin >> a >> b;		
		graph[a][b] = 1;	// a입장에서 큰 경우 1로 저장	
		graph[b][a] = 2;	// b입장에서 작은 경우 2로 저장
	}

	for (int k = 1; k <= N; k++) {	// 플로이드 워셜 개념. 그러나 최단 거리가 아니라 방향만을 넣음
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][k] != 0 && graph[i][k] == graph[k][j])	// i에서 k로 비교가 이루어졌고 같은 방향일때
					graph[i][j] = graph[i][k];	// 기존에 1이었다가 2로 바뀔일 없음. 비교 방향에 따라 커졌다 작아졌다 할 리가 없음
			}
		}
	}

	//print(N, M);

	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] == 0) cnt++;	// 0이 아니면 비교가 이뤄졌다는 의미
		}
		cout << cnt - 1 << endl;	// 자기 자신은 제외 해야 되므로 -1 해서 출력
	}
}