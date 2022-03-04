#include<stdio.h>
#include<vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> swit;
	swit.push_back(0);				// 1��° �ε������� Ȯ���ϱ� ���� �ǹ̾��� 0�� �־���
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		swit.push_back(x);
	}
	int student;
	scanf("%d", &student);
	for (int i = 0; i < student; i++) {
		int gender, num;
		scanf("%d %d", &gender, &num);
		switch (gender) {
		case 1:
			for (int i = num; i <= n; i++) {		// ������ ��� num ���� �ε����� �� �ʿ� ����
				if (i % num == 0) {					// num�� ����� ��� ���� �ٲ�
					swit[i] = (swit[i] + 1) % 2;
				}
			}
			break;
		case 2:
			swit[num] = (swit[num] + 1) % 2;		// ������ ��� num��° �ε����� ������ ����
			for (int i = 1; i <= n; i++) {
				int left = num - i;					// �¿� �ε��� ��Ī �̵�
				int right = num + i;
				if ((left < 1) || (right > n))		// �ε��� ������ �Ѿ�� break;
					break;

				if (swit[left] == swit[right]) {	// �¿� ������ �� �ٲ���
					swit[left] = (swit[left] + 1) % 2;
					swit[right] = swit[left];
				}
				else								// ��Ī�� �ƴϸ� ����
					break;
				
			}
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", swit[i]);
		if (i % 20 == 0)
			printf("\n");
	}
}