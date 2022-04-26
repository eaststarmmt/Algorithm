#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;
int graph[51][51];
int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		fill(graph[i], graph[i] + N + 1, INF);
	}   // end of for

	for (int i = 0; i < road.size(); i++) {  // A마을부터 B마을까지 경로가 한개가 아니므로 최솟값 저장
		graph[road[i][0]][road[i][1]] = min(graph[road[i][0]][road[i][1]], road[i][2]);
		graph[road[i][1]][road[i][0]] = min(graph[road[i][1]][road[i][0]], road[i][2]);
	}   // end of for
	// 플로이드 워셜 이용
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	for (int i = 2; i <= N; i++) {   // 1번부터 K안에 들어오는 거리 수 카운팅
		if (graph[1][i] <= K) {
			answer++;
		}
	}
	return ++answer;    // 자기 자신까지 카운팅
}