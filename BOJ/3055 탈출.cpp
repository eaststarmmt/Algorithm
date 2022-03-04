#include<iostream>
#include<queue>
#include<string>
using namespace std;

char map[52][52];

int hedR, hedC, waterR, waterC, beaverR, beaverC;
int cnt;

int R, C;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1 , 1 };

queue<pair<int, int>> water, hed;

bool bfs() {
	
	hed.push({ hedR, hedC });
	while(!hed.empty()) {

		cnt++;
		int travel = water.size();				// ť�� enqueue �۾��� ��� �� ���̱� ������ ����� �̸� ��ƾ� ��

		for(int i = 0; i < travel; i++) {		// water ť�� ����ִ� ��ŭ �� ������� Ȯ��
			int r = water.front().first;
			int c = water.front().second;
			water.pop();
			for (int j = 0; j < 4; j++) {
				int nr = r + dr[j];
				int nc = c + dc[j];
				if (map[nr][nc] == '.' || map[nr][nc] == 'S') {			// �� ���̸� �� Ȯ���ϰ� Ǫ��
					water.push({ nr, nc });
					map[nr][nc] = '*';
				}
			}
		}


		travel = hed.size();

		for (int i = 0; i < travel; i++) {	// hed�� ����ִ� ������ ��ŭ ����ġ�� �� �� 4�� Ȯ��
			int r = hed.front().first;
			int c = hed.front().second;
			hed.pop();
			for (int j = 0; j < 4; j++) {
				int nr = r + dr[j];
				int nc = c + dc[j];

				if (map[nr][nc] == '.') {		// �� ���̸� Ȯ��
					hed.push({ nr, nc });
					map[nr][nc] = 'S';
				}
				else if (map[nr][nc] == 'D') {	// �������� �����ϸ� true ��ȯ
					return true;
				}
			}
		}
	
	}
	return false;	// �̵���ΰ� �� ����������� ������ ������ false

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	int R, C;
	cin >> R >> C;
	string input;
	
	for (int i = 1; i <= R; i++) {
		cin >> input;
		for (int j = 1; j <= C; j++) {
			map[i][j] = input[j - 1];
			switch (input[j - 1]) {
			case 'D':
				beaverR = i;
				beaverC = j;
				break;
			case '*':
				water.push({ i, j });	// ���� �������� ���� ���� �־ �̸� �޾� ����
				break;
			case 'S':
				hedR = i;
				hedC = j;
				break;
			}
		}
	}
	if (bfs()) cout << cnt << "\n";
	else cout << "KAKTUS\n";
}