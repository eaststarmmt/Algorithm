#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define INF 1e9
using namespace std;

vector<int> graph[11];
int pop[11], comp[11];
int visited[11];
int N;

pair<int, int> dfs(int x, int target) {
	visited[x] = 1;
	pair<int, int> ret = { 1, pop[x] };	// <구역 숫자, 인구 수>
	for (int there : graph[x]) {
		if (comp[there] != target) {		// 다른 구역이면 무시
			continue;
		}
		if (visited[there]) {
			continue;
		}

		pair<int, int> temp = dfs(there, target);
		ret.first += temp.first;
		ret.second += temp.second;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> pop[i];
	}
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int x;
			cin >> x;
			graph[i].push_back(x);
		}	// end of for j
	}	// end of for
	int res = INF;
	for (int i = 1; i < (1 << N) - 1; i++) {		// N번 shift하면 N + 1 가지 경우. 그래서 등호 없애고 -1 빼야됨(전체 제외해야 하므로) 
		memset(visited, 0, sizeof(visited));
		memset(comp, 0, sizeof(comp));
		int idx1 = -1;
		int idx2 = -1;

		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				comp[j + 1] = 1;	// 구역 표시. 1과 0으로 나눔
				idx1 = j + 1;
			}
			else {
				idx2 = j + 1;
			}
		}	// end of for j
		pair<int, int> res1 = dfs(idx1, 1);
		pair<int, int> res2 = dfs(idx2, 0);

		if (res1.first + res2.first != N) {
			continue;
		}
		res = min(res, abs(res1.second - res2.second));
	}	// end of for i
	cout << (res == INF ? -1 : res) << "\n";
	return 0;
}