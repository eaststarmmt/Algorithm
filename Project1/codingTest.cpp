#include<cstdio>
#include<vector>
using namespace std;

int map[20][20];
int dice[6];
int N, M;
int x, y, k;
vector<int> com;
int dr[] = { 0, 0, 0, -1, 1 };	// 주사위 위치 상 하 좌 우 앞 뒤
int dc[] = { 0, 1, -1, 0, 0 };

void changeNumber(int r, int c) {	// 숫자 바꾸는 부분
	x = r;
	y = c;
	if (map[x][y] == 0) {		// 바닥이 0인 경우
		map[r][c] = dice[1];	// 지도에 주사위 바닥 숫자 복사
	}
	else {						// 바닥 1인 경우
		dice[1] = map[r][c];	// 바닥에 맵 숫자 복사 후 바닥은 0으로
		map[r][c] = 0;
	}
}

bool rollDice(int commend) {
	// 범위 밖인지 먼저 확인
	int nr = x + dr[commend];
	int nc = y + dc[commend];

	if (nr < 0 || nc < 0 || nr >= N || nc >= M) return false;	// 범위 벗어나면 바로 false로 끊어버림
	int temp = dice[0];		// 일관성 있게 위를 임시변수에 저장해서 돌림
	switch (commend) {		// 이거 switch 말고 if가 중복 덜 있었을거같은데...
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

	changeNumber(nr, nc);		// 바닥과 관계 확인해서 숫자 바꿔줘야됨

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
		if(rollDice(com[i]))		// true면 값 출력
			printf("%d\n", dice[0]);
	}
}