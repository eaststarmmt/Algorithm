#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct StudentInfo {
	int student;
	int like[4];
};

struct Pos {
	int r, c, empty_cnt, like_cnt;
};

bool cmp(Pos a, Pos b) {	// ���� ���ǿ� �°� cmp ����
	if (a.like_cnt == b.like_cnt) {
		if (a.empty_cnt == b.empty_cnt) {
			if (a.r == b.r) {
				return a.c < b.c;
			}
			return a.r < b.r;
		}
		return a.empty_cnt > b.empty_cnt;
	}
	return a.like_cnt > b.like_cnt;
}
int satis[5] = { 0, 1, 10, 100, 1000 };
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
vector<StudentInfo> student_list;
vector<Pos> pos_list;
vector<int> like_list[401];
int map[21][21];
int N;

int main() {
	scanf("%d", &N);
	int like[4] = { 0 };
	for (int i = 0; i < N * N; i++) {
		int student;
		scanf("%d", &student);
		for (int j = 0; j < 4; j++) {
			scanf("%d", &like[j]);
			like_list[student].push_back(like[j]);
		}
		student_list.push_back({ student, like[0], like[1], like[2], like[3] });
	}	// end of input
	// �ڸ���ġ
	for (int i = 0; i < student_list.size(); i++) {
		int student = student_list[i].student;
		pos_list.clear();
		for (int r = 1; r <= N; r++) {	// �ڸ����� �˻�
			for (int c = 1; c <= N; c++) {
				if (map[r][c] != 0) continue;	// �� �ڸ� �ƴϸ� ����
				int empty_cnt = 0;
				int like_cnt = 0;
				for (int n = 0; n < 4; n++) {
					int nr = r + dr[n];
					int nc = c + dc[n];
					if (nr > 0 && nr <= N && nc > 0 && nc <= N) {
						if (map[nr][nc] == 0) {	// ��ĭ�̸� ��ĭ ī����
							empty_cnt++;
							continue;	// ��ĭ�̴ϱ� �����ϴ� �л� Ȯ���� �ʿ� ����
						}
						for (int k = 0; k < 4; k++) {
							if (map[nr][nc] == student_list[i].like[k]) {	// �����ϴ� �л��̸� ī����
								like_cnt++;
								break;
							}
						}
					}
				}
				pos_list.push_back({ r, c, empty_cnt, like_cnt });	// �ڸ� ���� ����
			}
		}
		sort(pos_list.begin(), pos_list.end(), cmp);
		map[pos_list[0].r][pos_list[0].c] = student;	// ���ǿ� ���� �´� �ڸ��� �л� ��ġ
	}
	int res = 0;
	// ������ ����
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int student = map[r][c];
			int cnt = 0;
			for (int n = 0; n < 4; n++) {	// ��濡 �����ϴ¾� ��� �ִ��� ī����
				int nr = r + dr[n];
				int nc = c + dc[n];
				if (nr < 1 || nr > N || nc < 1 || nc > N) continue;
				for (int l = 0; l < 4; l++) {
					if (like_list[student][l] == map[nr][nc]) {	// �����ϴ� �л� ������ ī����
						cnt++;
						break;
					}
				}
			}
			res += satis[cnt];
		}
	}
	printf("%d\n", res);
}