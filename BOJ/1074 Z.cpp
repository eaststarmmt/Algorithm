#include<stdio.h>
#include<cmath>
using namespace std;

int N, r, c;
int cnt;
void divideCon(int startR, int startC, int size) {
	if (startR == r && startC == c) {	// 원하는 위치 찾았을 때
		printf("%d", cnt);
		return;
	}
	
	if (startR <= r && r < startR + size && startC <= c && c < startC + size) {		// 범위 내에 있는 경우
		divideCon(startR, startC, size / 2);					// 왼쪽부터 순서대로 찾아야 됨. 안그러면 카운팅 꼬임
		divideCon(startR, startC + size / 2, size / 2);
		divideCon(startR + size / 2, startC, size / 2);
		divideCon(startR + size / 2, startC + size / 2, size / 2);
	}
	else {
		cnt += size * size;		// 범위 내에 없는 경우는 현재 갖고 있는 size의 제곱을 더함. 어차피 순서대로 했기 때문에 더해주면 됨
	}
}

int main() {
	scanf("%d %d %d", &N, &r, &c);
	divideCon(0, 0, 1 << N);
}