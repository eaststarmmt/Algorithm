#include<cstdio>
#include<vector>
using namespace std;

int map[20][20];
int dice[6];
int N, M;
int x, y, k;
vector<int> com;
int dr[] = { 0, 0, 0, -1, 1 };	// �ֻ��� ��ġ �� �� �� �� �� ��
int dc[] = { 0, 1, -1, 0, 0 };

void changeNumber(int r, int c) {	// ���� �ٲٴ� �κ�
	x = r;
	y = c;
	if (map[x][y] == 0) {		// �ٴ��� 0�� ���
		map[r][c] = dice[1];	// ������ �ֻ��� �ٴ� ���� ����
	}
	else {						// �ٴ� 1�� ���
		dice[1] = map[r][c];	// �ٴڿ� �� ���� ���� �� �ٴ��� 0����
		map[r][c] = 0;
	}
}

bool rollDice(int commend) {
	// ���� ������ ���� Ȯ��
	int nr = x + dr[commend];
	int nc = y + dc[commend];

	if (nr < 0 || nc < 0 || nr >= N || nc >= M) return false;	// ���� ����� �ٷ� false�� �������
	int temp = dice[0];		// �ϰ��� �ְ� ���� �ӽú����� �����ؼ� ����
	switch (commend) {		// �̰� switch ���� if�� �ߺ� �� �־����Ű�����...
	case 1:	
		dice[0] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[3];
		dice[3] = temp;
		break;
	case 2:
		dice[0] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[2];
		dice[2] = temp;
		break;
	case 3:
		dice[0] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[5];
		dice[5] = temp;
		break;
	case 4:
		dice[0] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[4];
		dice[4] = temp;
		break;
	}

	changeNumber(nr, nc);		// �ٴڰ� ���� Ȯ���ؼ� ���� �ٲ���ߵ�

	return true;
}

int main() {
	
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &k);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < k; i++) {
		int c;
		scanf("%d", &c);
		com.push_back(c);
	}

	for (int i = 0; i < k; i++) {
		if(rollDice(com[i]))		// true�� �� ���
			printf("%d\n", dice[0]);
	}
}