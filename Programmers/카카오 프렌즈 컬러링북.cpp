#include <vector>
#include <cstring>
using namespace std;
int max_size_of_one_area, now_size;
bool visited[100][100];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int R, C;
void dfs(vector<vector<int>> picture, int r, int c, int target) {
	visited[r][c] = true;   // �̵� ǥ��
	now_size++;             // ���� �׸� ũ�� ī����
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc])
			continue;
		if (!visited[nr][nc] && picture[nr][nc] == target)   // �湮���� ���� ���� ������ ��츸 �湮
			dfs(picture, nr, nc, target);
	}
}
// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	max_size_of_one_area = 0;
	R = picture.size();
	C = picture[0].size();
	memset(visited, false, sizeof(visited));    // visited �ʱ�ȭ ���ϸ� Ʋ��
	for (int i = 0; i < picture.size(); i++) {
		for (int j = 0; j < picture[i].size(); j++) {
			if (!visited[i][j] && picture[i][j] != 0) {   // �湮�� �� ���� ��ĥ �� ��츸
				now_size = 0;   // ���� �׸� ũ�� �ʱ�ȭ
				dfs(picture, i, j, picture[i][j]);
				number_of_area++;       // �׸� ���� ī����
				max_size_of_one_area = now_size > max_size_of_one_area ? now_size : max_size_of_one_area;   // ������� �� ������ �ִ��� �� ����
			}
		}
	}   // end of picture
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}