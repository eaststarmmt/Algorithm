#include<iostream>
#include<vector>
#define endl "\n"
using namespace std;

class Cctv {
public:
	int r, c, type;
	Cctv(int r, int c, int type) {
		this->r = r;
		this->c = c;
		this->type = type;
	}
};

int R, C;
vector<Cctv> cctv;
int map[8][8];
int res = 1e9;
int rotation[] = { 0, 4, 2, 4, 4, 1 };

void mapCopy(int src[8][8], int des[8][8]) {	// �� �����ϱ�
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			des[i][j] = src[i][j];
		}
	}
}

void check(int dir, Cctv cctv) {
	dir %= 4;
	switch (dir) {

	case 0:		// ��
		for (int r = cctv.r - 1; r >= 0; r--) {
			if (map[r][cctv.c] == 6) break;
			map[r][cctv.c] = -1;
		}
		break;

	case 1:		// ����
		for (int c = cctv.c - 1; c >= 0; c--) {
			if (map[cctv.r][c] == 6) break;
			map[cctv.r][c] = -1;
		}
		break;

	case 2:		// �Ʒ�
		for (int r = cctv.r + 1; r < R; r++) {
			if (map[r][cctv.c] == 6) break;
			map[r][cctv.c] = -1;
		}
		break;

	case 3:		// ����
		for (int c = cctv.c + 1; c < C; c++) {
			if (map[cctv.r][c] == 6) break;
			map[cctv.r][c] = -1;
		}
		break;
	}
}

void comb(int cnt) {	
	if (cnt == cctv.size()) {	// cctv�� �� Ȯ�� ������
		int blind = 0;	// �簢����

		for (int i = 0; i < R; i++) {	
			for (int j = 0; j < C; j++) {
				if (map[i][j] == 0) blind++;
			}
		}
		res = blind < res ? blind : res;
		return;
	}

	int copy_map[8][8];
	int type = cctv[cnt].type;

	for (int i = 0; i < rotation[type]; i++) {	// cctv ���� �����ϱ�
		mapCopy(map, copy_map);		// �� ���
		
		switch (type) {
		case 1:	// 1���� �ܹ���
			check(i, cctv[cnt]);
			break;

		case 2:	// 2���� 180�� �� ��
			check(i, cctv[cnt]);
			check(i + 2, cctv[cnt]);
			break;

		case 3:	// 90�� 2��
			check(i, cctv[cnt]);
			check(i + 1, cctv[cnt]);
			break;

		case 4:	// ������
			check(i, cctv[cnt]);
			check(i + 1, cctv[cnt]);
			check(i + 2, cctv[cnt]);
			break;

		case 5:	// �׹���
			check(i, cctv[cnt]);
			check(i + 1, cctv[cnt]);
			check(i + 2, cctv[cnt]);
			check(i + 3, cctv[cnt]);
			break;
		}

		comb(cnt + 1);
		mapCopy(copy_map, map);		// �� ����
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				cctv.push_back(Cctv(i, j, map[i][j]));
			}
		}
	}	// end of input

	comb(0);
	cout << res << endl;
}