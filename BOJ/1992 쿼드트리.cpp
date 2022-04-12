#include<stdio.h>
using namespace std;

int quad[65][65];
int n;

void divide(int x, int y, int size) {
	if (size == 1) {
		printf("%d", quad[x][y]);
		return;
	}
	for (int i = x; i < x + size; i++) {	
		for (int j = y; j < y + size; j++) {	// j 값 증가할때마다 오른쪽으로 이동
			if (quad[i][j] != quad[x][y]) {		// 처음값이랑 다르면 바로 나눔
				printf("(");				//같지 않을때만 괄호 생김
				divide(x, y, size / 2);			//왼쪽 위
				divide(x, y + (size / 2), size / 2);	//오른쪽 위
				divide(x + (size / 2), y, size / 2);	//왼쪽 아래
				divide(x + (size / 2), y + (size / 2), size / 2);	//오른쪽 아래
				printf(")");		// 쪼개진 부분 여기서 끝남. 그러므로 여기서 괄호 닫으면 됨
				return;				// 같지 않은 순간 재귀로 돌리고 그 아래는 할 필요 없음
			}
		}
	}
	printf("%d", quad[x][y]);	//정해진 범위 다 끝났는데 같을때 값 출력
	
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &quad[i][j]);
		}
	}
	
	divide(1, 1, n);
	printf("\n");
}