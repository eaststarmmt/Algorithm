#include <string>
#include <vector>
#include<iostream>
using namespace std;

bool graph[101][101];

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	// 플로이드 워셜 문제
	for (int i = 0; i < results.size(); i++) {
		graph[results[i][0]][results[i][1]] = true;
	}   // 단순하게 승부를 봤는지만 알면 되기 때문에 무조건 true로 표시. 단방향으로 표시해야됨. 양방향으로 표시하면 모든 선이 이어짐

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (graph[i][k] && graph[k][j]) {
					graph[i][j] = true;
				}
			}
		}
	}   // 거쳐 가는 모든 경로 체크

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] || graph[j][i]) cnt++;   // 본인끼리는 어차피 false라 알아서 빠짐. 두개중에 하나라도 true 이면 싸웠음
		}
		if (cnt == n - 1) answer++;
	}

	return answer;
}