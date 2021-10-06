#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;

int N, P, E;
bool selected[20];	// ���տ��� ���õ� �� �������� Ȯ�ο�
vector<pair<int, int>> member;	// ��ü ��� �ּҰ� �ִ밪 �޴� ����
int minTotal, maxTotal;

void check(vector<int> recipient) {
	int distribute[20] = { 0 };		// ���� ��� �й�Ǵ��� ��¿�
	int surplus = E - minTotal;		// ���õ� �ΰ����� ���� �ּҰ��� ��ü �������� ����
	for (int i = 0; i < recipient.size(); i++) {
		int x = member[recipient[i]].first;		// �������� ���� x, y
		int y = member[recipient[i]].second;	// x���� ���� ����� �ּҰ�, y���� �ִ밪
		distribute[recipient[i]] = x;		// �й�� �ϴ� �ּҰ��� �־���� ������

		if (surplus == 0) continue;		// ���� ������ 0�̸� ���� ����. break�� ���ϴ� ������ �� ������� �ּҰ��� ���� ������� �ʾұ� ����

		if (surplus > y - x) {			// �ִ밪 - �ּҰ��� �׿� ���� ���ؼ� �׿��� �� ������ �� ����� ���뷮 ��ŭ ����
			distribute[recipient[i]] += y - x;
			surplus -= y - x;
		}
		else {					// �׿��� �� ������ ���� �� �����. �̷��� ������ 0�� �Ǵ°�찡 �־ 19��° �ٷ� �ð��� ����
			distribute[recipient[i]] += surplus;	
			surplus = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", distribute[i]);
	}
	printf("\n");
	exit(0);					// �� �̻� ������ �ʿ� �����Ƿ� �ٷ� ����
}

void comb(int start, int cnt) {
	if (cnt == P) {					// P�� ��ŭ ���õ� ���. ��������
		vector<int> recipient;		// ������� �ε��� �־� ���� ����
		minTotal = 0, maxTotal = 0;	// �ּҰ� �� �հ� �ִ밪 �� �� ������ ����
		for (int i = 0; i < N; i++) {
			if (selected[i]) {
				minTotal += member[i].first;	// �ּҰ� ���� ������
				maxTotal += member[i].second;	// �ִ밪 ���� ������
				recipient.push_back(i);			// �ε��� ����
			}
		}
		if (minTotal <= E && maxTotal >= E) {	// �ּҰ� �� �հ� �ִ밪 �� �� ���̿� E�� ��������� ���õ� ������� E�� ����� ����
			check(recipient);					// ���õ� ��� �ε����� ���� ���͸� ����
		}
		return;
	}

	for (int i = start; i < N; i++) {		// �׳� ����
		selected[i] = true;
		comb(i + 1, cnt + 1);
		selected[i] = false;
	}
}

int main() {
	
	scanf("%d %d %d", &N, &P, &E);

	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		member.push_back({ x, y });
	}

	comb(0, 0);
	printf("%d\n", -1);		// ������� ������ ����� �� �����ٴ� ���̹Ƿ� -1 ���
}