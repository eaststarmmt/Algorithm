#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int map[25][25];		// 2차원 배열 형식이라 vector를 사용 못해서 다른 방법을 사용
bool visited[25][25];
int complex = 1;		// 단지 개수 카운팅
int cnt;

bool dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n) return false;	// 범위를 벗어나면 false
	if (visited[x][y]) return false;						// 이미 방문했으면 false
	visited[x][y] = true;									// 방문 표시 but 아직 아파트 인지는 모름
	if (map[x][y] > 0) {								// 0보다 크면 아파트. 이제는 dfs 방식으로 카운팅
		cnt++;
		map[x][y] = complex;
		dfs(x + 1, y);									// 좌표로 탐색을 한다. 현재 위치에서 4방을 재귀로 탐색
		dfs(x - 1, y);
		dfs(x, y + 1);
		dfs(x, y - 1);
		return true;								// 아파트 단지 이므로 true 반환
	}
	else
		return false;
	
}

int main() {
	scanf("%d", &n);
	vector<int> result;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dfs(i, j)) {				// true가 나오면 아파트 단지
				complex++;					// 단지를 카운팅 하기위해 1 증가
				result.push_back(cnt);		// 단지 내에 몇채가 있었는지 카운팅 한 값을 벡터에 저장
				cnt = 0;				// 다음 카운팅을 위해 0으로 초기화
			}
		}
	}
	sort(result.begin(), result.end());
	printf("%d\n", complex - 1);
	for (auto x : result) {
		printf("%d\n", x);
	}
	
}
