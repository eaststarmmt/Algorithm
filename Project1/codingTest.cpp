#include<cstdio>
using namespace std;

int main() {
	long long k;
	scanf("%lld", &k);
	int flag = 0;	// ¦������ �Ѿ������ �� ���� �ٲ�°� ����ؼ� �÷��� ���� �غ�
	while (1) {
		if (k == 1) {
			printf("%d", (0 + flag) % 2);	
			break;
		}
		else if (k == 2) {			
			printf("%d", (1 + flag) % 2);
			break;
		}
		if (k % 2 == 1) k = k / 2 + 1;	// Ȧ���� ��쿡�� /2 +1 �� �ε����� ���� ���� ����
		else {							// ¦���� /2 �� �ε����� �ݴ� ���� ����
			k = k / 2;
			flag = (flag + 1) % 2;
		}
	}
}