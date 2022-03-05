#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> dis;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int x;
		scanf("%d", &x);
		dis.push_back(x);
	}
	vector<int> fuel;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		fuel.push_back(x);
	}
	int minFuel = fuel[0];	// �⸧ �ּڰ� ����
	long result = (long)fuel[0] * dis[0];	// �� ��° ���ñ��� ���µ� �ʿ��� �⸧��
	for (int i = 1; i < n - 1; i++) {
		minFuel = min(minFuel, fuel[i]);	// ������� �⸧�� �� �ּ� �⸧�� ã��
		result += (long)minFuel * dis[i];	// �ּ� �⸧���� �Ÿ��� ���� �����༭ ������� ���µ� ��� �ּ� ��� ���
	}
	printf("%lld\n", result);
}