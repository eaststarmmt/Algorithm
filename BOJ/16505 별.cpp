#include<stdio.h>
#include<cmath>
using namespace std;

char star[1024][1024];

void recursive(int x, int y, int size) {
	if (size == 1) {
		star[x][y] = '*';
		return;
	}
	size /= 2;				// size를 2로 나눠서 1이 될때만 출력. 
	recursive(x, y, size);	// 모양이 1을 세방향씩 세번씩 증가하는 규칙임
	recursive(x + size, y, size);
	recursive(x, y + size, size);
}

int main() {
	int n;
	scanf("%d", &n);
	int size = pow(2, n);		// size를 2^n 으로 받음
	recursive(0, 0, size);	
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j == size - i)	// 예제 보면 계속 size에서 하나씩 줄어듬. 공백 없이 출력하기 위함
				break;
			if (star[i][j] == '*')	// 배열에서 *을 만나면 출력 아니면 공백
				printf("%c", star[i][j]);
			else 
				printf(" ");
		}
		if(i != size - 1)		// 마지막에 줄바꿈을 없애기 위함
			printf("\n");
	}
	
}