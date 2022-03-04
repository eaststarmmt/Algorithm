#include<iostream>
#include<set>
#include<cstring>
#define endl "\n"
using namespace std;

int N, result;
int want[100001];
bool visited[100001];	// 방문 그 자체를 했는지 확인용
bool team[1000001];		// 팀이 되는지 확인 했는지 확인용. 일단 한번 재귀를 타면 팀이 만들어지던 아니던 결론이 남

void dfs(int now) {
	visited[now] = true;
	if (!visited[want[now]]) dfs(want[now]);	// 방문한 적이 없다면 재귀로 들어감
	else {
		if (!team[want[now]]) {		// 방문을 했는데 팀이 되는지 확인한 적이 없다면 사이클이 돌았으므로 팀이 완성
			while (!team[now]) {	
				team[now] = true;	// 팀이 되었으므로 표시
				now = want[now];	// 다음 원하는 사람으로 now 이동
				result--;			// 한명 팀이 나왔으므로 전체에서 1 빼줌
			}
		}
	}
	team[now] = true;	// 팀이 안되더라도 여기서 표시 하면 팀이 안되던 되던 더이상 확인할 필요가 없음
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> N;
		result = N;
		memset(visited, false, sizeof(visited));	
		memset(team, false, sizeof(team));
		for (int i = 1; i <= N; i++) {
			cin >> want[i];
		}
		for (int i = 1; i <= N; i++) {
			if (team[i] || visited[i]) continue;	// 방문했으면 무시
			dfs(i);
		}
		cout << result << endl;
	}
}