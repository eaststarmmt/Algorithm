#include<cstdio>
using namespace std;

void moo(int N) {
	int S = 3;		// ���� S ������ ��
	int mid = 4;	// �߰��� moooo �̺κ�
	
	while(N > S) {	// ������ ���° ������ Ȯ���ϴ� ����
		S = S * 2 + mid;
		mid++;
	}
	mid--;			// mid�� ���ʿ��ϰ� �ѹ� �þ�� �ٽ� ������

	while (true) {		// moooooo �̺κи� ����� �� �����°� ����
		int preS = (S - mid) / 2;	// ���� ������ ����

		if (N <= preS) {	// �պκ��϶� �պκи� ����� �ٽ� ����
			S = preS;
			mid--;
		}
		else if (N > mid + preS) {	// �޺κ��϶� N���� �տ� �� �κ� �������� �պκ��ΰ�ó�� �ٲٰ� �ٽ� ���� ����
			N -= mid + preS;
			mid--;
			S = preS;
		}
		else {		// �߰��κ��̸� �պκ� �����ְ� ���� Ż��
			N -= preS;
			break;
		}
		
	}
	if (N == 1) printf("m\n");	// mooooo �̺κи� ���� ��Ȳ�̹Ƿ� ù��° �ƴϸ� ������ o
	else printf("o\n");
}

int main() {
	int N;
	scanf("%d", &N);

	moo(N);
}