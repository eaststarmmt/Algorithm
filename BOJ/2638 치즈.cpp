#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

int map[100][100];
bool visited[100][100];
bool air[100][100];
int N, M;
int time;
int cheezeCnt;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int dfsCnt;

class Air {			// ���Ϳ� ��ǥ �ֱ� ����. �׳� �Ẹ�� �;���
public:
	int r, c;
	Air(int r, int c) {
		this->r = r;
		this->c = c;
	}
};

vector<Air> cheezeVec;		// ���� ġ� ������ ����

void dfs(int r, int c) {
	air[r][c] = true;
	visited[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr >= 0 && nr < N && nc >= 0 && nc < M && !visited[nr][nc] && map[nr][nc] == 0) {
			dfs(nr, nc);
		}
	}
}

void removeCheeze() {		// ġ�� �����ִ� �Լ�
	for (int i = 0; i < cheezeVec.size(); i++) {
		map[cheezeVec[i].r][cheezeVec[i].c] = 0;
	}
}

void cheeze(int r, int c) {		// ġ� ����� 2�� �̻� ��Ҵ��� Ȯ��
	int airCnt = 0;
	for (int i = 0; i < 4; i++) {	// ��� Ž�� �̿�
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr >= 0 && nr < N && nc >= 0 && nc < M && air[nr][nc]) {
			airCnt++;
			if (airCnt == 2) {		// �α��� �̻� ������� 
				cheezeVec.push_back(Air(r, c));	// �ٷ� 0 ó���ϸ� ���� ġ� ����� �ϳ��� ��Ҵµ��� �������� ��찡 ���� �� ����
				cheezeCnt--;			// �׷��Ƿ� ���Ϳ� �־ ���� ���� �۾� ����
				return;
			}
		}
	}
	
}


void bfs() {				// �������� ġ�� Ž��
	memset(visited, false, sizeof(visited));
	queue<Air> Q;
	Q.push(Air(0, 0));
	while (!Q.empty()) {
		int r = Q.front().r;
		int c = Q.front().c;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nc >= 0 && nr < N && nc < M && !visited[nr][nc]) {
				
				visited[nr][nc] = true;

				if (map[nr][nc] == 1)		// ġ���� ���
					cheeze(nr, nc);			// Ȯ���۾�
				else
					Q.push(Air(nr, nc));	// ������ ��� push
			}
			
		}
		
		if (cheezeCnt == 0) return;		// ġ� ������ ����
	}

}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)		// ġ�� ���� �̸� ī����
				cheezeCnt++;
		}
	}	// end of for input

	while (cheezeCnt > 0) {
		memset(air, false, sizeof(air));	// ���⸦ dfs�� ã�ƾ� ġ�� �ӿ� ���⸦ ���� ���� ����
		memset(visited, false, sizeof(visited));	// dfs�� ġ�� �� ���⸦ ã�� ���� visited �迭 �ʱ�ȭ
		dfs(0, 0);

		bfs();				// ������ ġ�� Ž��
		removeCheeze();		// bfs�� ��� ���� �� ġ�� ����
		cheezeVec.clear();
	}

	printf("%d\n", time);
}