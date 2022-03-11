#include <vector>
#include <cstring>
using namespace std;
int max_size_of_one_area, now_size;
bool visited[100][100];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int R, C;
void dfs(vector<vector<int>> picture, int r, int c, int target) {
	visited[r][c] = true;   // 이동 표시
	now_size++;             // 현재 그림 크기 카운팅
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc])
			continue;
		if (!visited[nr][nc] && picture[nr][nc] == target)   // 방문한적 없고 같은 색깔인 경우만 방문
			dfs(picture, nr, nc, target);
	}
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	max_size_of_one_area = 0;
	R = picture.size();
	C = picture[0].size();
	memset(visited, false, sizeof(visited));    // visited 초기화 안하면 틀림
	for (int i = 0; i < picture.size(); i++) {
		for (int j = 0; j < picture[i].size(); j++) {
			if (!visited[i][j] && picture[i][j] != 0) {   // 방문한 적 없고 색칠 한 경우만
				now_size = 0;   // 현재 그림 크기 초기화
				dfs(picture, i, j, picture[i][j]);
				number_of_area++;       // 그림 영역 카운팅
				max_size_of_one_area = now_size > max_size_of_one_area ? now_size : max_size_of_one_area;   // 현재까지 중 사이즈 최대인 값 저장
			}
		}
	}   // end of picture
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}