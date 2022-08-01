#include <string>
#include <vector>
#include <algorithm>
#define INF 1e8

using namespace std;
int graph[201][201];
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 0;
	for (int i = 1; i <= n; i++) {     // 모든 거리 무한대로 초기화
		fill(graph[i], graph[i] + n + 1, INF);
	}
	for (int i = 0; i <= n; i++) {     // 자기 자신은 0으로 계산
		graph[i][i] = 0;
	}

	for (int i = 0; i < fares.size(); i++) { // 그래프에 가중치 저장
		int c = fares[i][0];
		int d = fares[i][1];
		int f = fares[i][2];

		graph[c][d] = f;
		graph[d][c] = f;
	}

	for (int k = 1; k <= n; k++) {   // 플로이드 워셜
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}   // end of for j
		}   // end of for i
	}   // end of for k
	answer = INF;

	for (int i = 1; i <= n; i++) {   // i 까지 가서 a, b 까지 가는 거리 중 가장 낮은 비용 계산. a, b도 포함 되기 때문에 한 집 먼저 가는것까지 포함됨
		answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]);
	}
	return answer;
}