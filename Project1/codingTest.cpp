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

class Air {			// 벡터에 좌표 넣기 위해. 그냥 써보고 싶었음
public:
	int r, c;
	Air(int r, int c) {
		this->r = r;
		this->c = c;
	}
};

vector<Air> cheezeVec;		// 지울 치즈를 저장할 벡터

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

void removeCheeze() {		// 치즈 지워주는 함수
	for (int i = 0; i < cheezeVec.size(); i++) {
		map[cheezeVec[i].r][cheezeVec[i].c] = 0;
	}
}

void cheeze(int r, int c) {		// 치즈가 공기랑 2번 이상 닿았는지 확인
	int airCnt = 0;
	for (int i = 0; i < 4; i++) {	// 사방 탐색 이용
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr >= 0 && nr < N && nc >= 0 && nc < M && air[nr][nc]) {
			airCnt++;
			if (airCnt == 2) {		// 두군데 이상 닿았을때 
				cheezeVec.push_back(Air(r, c));	// 바로 0 처리하면 다음 치즈가 공기랑 하나만 닿았는데도 지워지는 경우가 생길 수 있음
				cheezeCnt--;			// 그러므로 벡터에 넣어서 따로 뺴는 작업 진행
				return;
			}
		}
	}
	
}


void bfs() {				// 지워지는 치즈 탐색
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

				if (map[nr][nc] == 1)		// 치즈일 경우
					cheeze(nr, nc);			// 확인작업
				else
					Q.push(Air(nr, nc));	// 공기일 경우 push
			}
			
		}
		
		if (cheezeCnt == 0) return;		// 치즈가 없으면 종료
	}

}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)		// 치즈 개수 미리 카운팅
				cheezeCnt++;
		}
	}	// end of for input

	while (cheezeCnt > 0) {
		memset(air, false, sizeof(air));	// 공기를 dfs로 찾아야 치즈 속에 공기를 같이 세지 않음
		memset(visited, false, sizeof(visited));	// dfs로 치즈 밖 공기를 찾기 위해 visited 배열 초기화
		dfs(0, 0);

		bfs();				// 제거할 치즈 탐색
		removeCheeze();		// bfs가 모두 끝난 후 치즈 제거
		cheezeVec.clear();
	}

	printf("%d\n", time);
}