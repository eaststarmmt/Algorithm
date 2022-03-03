#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int A[202];		// �� ���� ���������� �α� ����
bool robot[101];
int N, K;

void turnWithBelt() {	// 1�� ��Ʈ�� ���� �̵�
	int tmp = A[1];
	A[1] = A[2 * N];	// 2N�� �ִ°� 1�� �̵�
	for (int i = 2 * N - 1; i >= 2; i--) {
		A[i + 1] = A[i];
	}	// end of turn A
	A[2] = tmp;
	
	for (int i = N - 1; i >= 1; i--) {	// �κ��� ��Ʈ�� ���� �̵�
		robot[i + 1] = robot[i];
	}
	robot[N] = false;	// N��°�� �̵��ؼ� ����. ��Ʈ�� ���� �̵��ؼ� ������ ���پ��
	robot[1] = false;	// ��Ʈ �̵������Ƿ� 1���� �������

}

void moveRobot() {	// �տ��� ó���ؼ� ������ N ĭ�� �������
	for (int i = N - 1; i >= 1; i--) {	
		if (robot[i] && A[i + 1] > 0 && !robot[i + 1]) {		// ���� ĭ�� ����ְ� �������� 0 �̻� ������
			robot[i + 1] = true;	// i + 1�� �̵�
			robot[i] = false;
			if (--A[i + 1] == 0)		// i + 1 ������ 1 ����
				K--;	// ī���� �� �ʿ� ���� K�� ����
		}
	}
	robot[N] = false;		// ������ ��ġ�� �ִ� �κ� ����
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