#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
struct Pos {
	int r, c;
};
int dr[] = { 0, -1, -1, -1, 0, 1, 1, 1 };	// �������� 1���� �����̶� -1 ����� ��
int dc[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int map[51][51];
int ans;
int N, M;
int d, s;
bool visited[51][51];
vector<Pos> cloud;

int rangeCheck(int x) {		// �� �ձ۰� �̾����ִ� �κ� ����
	if (x == 0) return N;
	if (x == N + 1) return 1;
	return x;

}

void moveCloud() {	// ���� �̵�
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < cloud.size(); i++) {
		int r = cloud[i].r;
		int c = cloud[i].c;
		int nr = r;
		int nc = c;
		for (int j = 0; j < s; j++) {	// �� ĭ�� �̵��ϸ鼭 ���� �Ѿ �κ� üũ
			nr += dr[d - 1];
			nc += dc[d - 1];
			nr = rangeCheck(nr);
			nc = rangeCheck(nc);
		}
		cloud[i].r = nr;
		cloud[i].c = nc;
	}
	for (int i = 0; i < cloud.size(); i++) {
		visited[cloud[i].r][cloud[i].c] = true;
	}
}

void addWater() {	// ������ �ִ� ĭ�� �� 1�� ����
	for (int i = 0; i < cloud.size(); i++) {
		map[cloud[i].r][cloud[i].c]++;
	}
}

void waterCopy() {	// �� ����. �밢�� �� ������ 1 ����
	for (int i = 0; i < cloud.size(); i++) {
		int r = cloud[i].r;
		int c = cloud[i].c;
		for (int i = 0; i < 4; i++) {	// �밢 ���� Ȯ��
			int nr = r + dr[2 * i + 1];
			int nc = c + dc[2 * i + 1];
			if (nr < 1 || nr > N || nc < 1 || nc > N || map[nr][nc] == 0) continue;	// �������� ����ų� ���� ���� ���
			map[r][c]++;
		}
	}
}

void createCloud() {	// �� 2 �̻��̰� ���� ������ ĭ�̸� ���� ����
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] >= 2 && !visited[i][j]) {
				cloud.push_back({ i, j });
				map[i][j] -= 2;
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}	// end of map

	for (int i = 0; i < 2; i++) {
		cloud.push_back({ N - i, 1 });
		cloud.push_back({ N - i, 2 });
	}	// end of initial cloud

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &d, &s);
		moveCloud();
		addWater();
		waterCopy();
		cloud.clear();
		createCloud();
	}	// end of M

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += map[i][j];
		}
	}
	printf("%d\n", ans);
}