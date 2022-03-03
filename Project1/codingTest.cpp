#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int A[202];		// 양 끝에 여유공간을 두기 위함
bool robot[101];
int N, K;

void turnWithBelt() {	// 1번 벨트랑 같이 이동
	int tmp = A[1];
	A[1] = A[2 * N];	// 2N에 있는거 1로 이동
	for (int i = 2 * N - 1; i >= 2; i--) {
		A[i + 1] = A[i];
	}	// end of turn A
	A[2] = tmp;
	
	for (int i = N - 1; i >= 1; i--) {	// 로봇도 벨트랑 같이 이동
		robot[i + 1] = robot[i];
	}
	robot[N] = false;	// N번째로 이동해서 빠짐. 벨트랑 같이 이동해서 내구도 안줄어듬
	robot[1] = false;	// 벨트 이동했으므로 1번은 비어있음

}

void moveRobot() {	// 앞에서 처리해서 무조건 N 칸은 비어있음
	for (int i = N - 1; i >= 1; i--) {	
		if (robot[i] && A[i + 1] > 0 && !robot[i + 1]) {		// 다음 칸이 비어있고 내구도가 0 이상 있을때
			robot[i + 1] = true;	// i + 1로 이동
			robot[i] = false;
			if (--A[i + 1] == 0)		// i + 1 내구도 1 감소
				K--;	// 카운팅 할 필요 없이 K를 떨굼
		}
	}
	robot[N] = false;		// 내리는 위치에 있는 로봇 제거
}

void putRobot() {
	if (A[1] > 0 && !robot[1]) {
		robot[1] = true;
		if (--A[1] == 0)
			K--;
	}
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= 2 * N; i++) {
		scanf("%d", &A[i]);
	}	// end of input
	int level = 0;
	while (K > 0) {
		level++;
		turnWithBelt();
		moveRobot();
		putRobot();
	}
	printf("%d\n", level);
}