#include<stdio.h>
using namespace std;

int map[129][129];
int blue;
int white;
void divCon(int x, int y, int size) {
	int check = map[x][y];	//뒤랑 비교하기 위해 첫번째 값 저장
	if (size == 1) {	//크기 1이면 카운팅만 하고 리턴
		if (check == 1) {
			blue++;
			return;
		}
		else {
			white++;
			return;
		}
	}		//x y 좌표 헷갈리면 피곤해짐. 이런문제 두번 세번 생각하고 풀기
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (check != map[i][j]) {		//값 다르면 재귀로 넘어가기
				divCon(x, y, size / 2);		
				divCon(x + (size / 2), y, size / 2);
				divCon(x, y + (size / 2), size / 2);
				divCon(x + (size / 2), y + (size / 2), size / 2);
				return;
			}
		}
	}
	if (check == 1) {
		blue++;
		return;
	}
	
	else {
		white++;
		return;
	}
	
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	divCon(1, 1, n);
	printf("%d\n%d\n", white, blue);
}