#include<cstdio>
#include<cmath>
using namespace std;

int main() {

	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {

		double sum = 0;
		double min = 9999999;
		double max = -1;
		for (int i = 0; i < 10; i++) {
			int x;
			scanf("%d", &x);
			sum += x;					// �Է��ϸ鼭 �� ����
			max = x > max ? x : max;	// �ִ밪 ���� �з�
			min = x < min ? x : min;	// �ּҰ� ���� �з�
		}
		sum = sum - max - min;			// �տ��� �ִ� �ּ� ����
		printf("#%d %d\n", test, (int)round(sum / 8));	// �ݿø� �� ���
	}

}