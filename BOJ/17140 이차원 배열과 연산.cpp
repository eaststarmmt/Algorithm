#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct Info {
	int cnt, num;
};

int map[101][101];
int R, C, K;
int Row, Col;	// ��� �� ���� ī���� �� ����
int counting[101];

bool cmp(Info a, Info b) {
	if (a.cnt == b.cnt)
		return a.num < b.num;
	return a.cnt < b.cnt;
}

void RCalc() {
	int tempCol = Col;
	Col = 0;	// �ִ� column ���� ������ ����
	for (int r = 1; r <= Row; r++) {
		vector<Info> info;	// �� �ٲ𶧸��� ���� �ؾ� ��
		fill(counting, counting + 101, 0);	// 0���� �ʱ�ȭ
		for (int c = 1; c <= tempCol; c++) {
			counting[map[r][c]]++;	// ���� ī����
		}	// end of counting
		for (int num = 1; num <= 100; num++) {
			if(counting[num] != 0)
				info.push_back({ counting[num], num });
		}	// end of push
		sort(info.begin(), info.end(), cmp);	// ���� Ƚ�� ���� �������� ����

		for(int c = 1; c <= tempCol; c++) {		// ������ col ���̰� �� �� ���� ���� ���°� ����
			map[r][c] = 0;
		}	

		int c = 0;
		for (int i = 0; i < info.size(); i++) {	// �ʿ� ���ο� �� ä���
			map[r][++c] = info[i].num;
			map[r][++c] = info[i].cnt;
		}
		Col = c > Col ? c : Col;	// �ִ밪 ���ϱ�
	}
}

void CCalc() {
	int tempRow = Row;
	Row = 0;
	for (int c = 1; c <= Col; c++) {
		vector<Info> info;
		fill(counting, counting + 101, 0);	// 0���� �ʱ�ȭ
		for (int r = 1; r <= tempRow; r++) {
			counting[map[r][c]]++;	// ���� ī����
		}	// end of counting
		for (int num = 1; num <= 100; num++) {
			if (counting[num] != 0)
				info.push_back({ counting[num], num });
		}	// end of push
		sort(info.begin(), info.end(), cmp);	// ���� Ƚ�� ���� �������� ����

		for (int r = 1; r <= tempRow; r++) {		// ������ row ���̰� �� �� ���� ���� ���°� ����
			map[r][c] = 0;
		}

		int r = 0;
		for (int i = 0; i < info.size(); i++) {	// �ʿ� ���ο� �� ä���
			map[++r][c] = info[i].num;
			map[++r][c] = info[i].cnt;
		}
		Row = r > Row ? r : Row;	// �ִ밪 ���ϱ�
	}
}

int main() {
	scanf("%d %d %d", &R, &C, &K);
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &map[i][j]);
		}
	}	// end of map
	Row = Col = 3;
	if (map[R][C] == K) {	// ó������ ���� �������� ��� 0 ��� �� ����
		printf("%d\n", 0);
		return 0;
	}
	for (int i = 1; i <= 100; i++) {
		if (Row >= Col) {
			RCalc();
		}
		else {
			CCalc();
		}
		if (map[R][C] == K) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("%d\n", -1);
}