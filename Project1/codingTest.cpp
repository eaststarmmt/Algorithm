#include<stdio.h>
#include<cmath>
using namespace std;

int N, r, c;
int cnt;
void divideCon(int startR, int startC, int size) {
	if (startR == r && startC == c) {	// ���ϴ� ��ġ ã���� ��
		printf("%d", cnt);
		return;
	}
	
	if (startR <= r && r < startR + size && startC <= c && c < startC + size) {		// ���� ���� �ִ� ���
		divideCon(startR, startC, size / 2);					// ���ʺ��� ������� ã�ƾ� ��. �ȱ׷��� ī���� ����
		divideCon(startR, startC + size / 2, size / 2);
		divideCon(startR + size / 2, startC, size / 2);
		divideCon(startR + size / 2, startC + size / 2, size / 2);
	}
	else {
		cnt += size * size;		// ���� ���� ���� ���� ���� ���� �ִ� size�� ������ ����. ������ ������� �߱� ������ �����ָ� ��
	}
}

int main() {
	scanf("%d %d %d", &N, &r, &c);
	divideCon(0, 0, 1 << N);
}