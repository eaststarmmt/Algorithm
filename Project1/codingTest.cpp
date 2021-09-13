#include<cstdio>
#include<algorithm>
#include<vector>
#define INF 1e9
using namespace std;

int main() {
	int N, H;
	scanf("%d %d", &N, &H);
	vector<int> up, down;
	for (int i = 0; i < N / 2; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		down.push_back(x);		// �ؿ��� �ھƿ����� ��
		up.push_back(y);		// ������ �������� ��
	}
	sort(down.begin(), down.end());	// �̺�Ž���� ���� ����
	sort(up.begin(), up.end());	

	int result = INF, cnt = 0;;


	for (int i = 1; i <= H; i++) {
		int sum, upBreak, downBreak;
		downBreak = lower_bound(down.begin(), down.end(), i) - down.begin();	// ������� ������ �� �ε���
		upBreak = upper_bound(up.begin(), up.end(), H - i) - up.begin();		// ��ü���� - ������̸� �ʰ��ϴ� ù��° ��� �ε���
		sum = N - downBreak - upBreak;	// ���� N / 2 - �ؿ��� �����¾� ù �ε���, N / 2 - ������ �����¾� ù �ε����̱� ������ N���� ����
		if (result > sum) {	// ���ο� �ּҰ� �߰ߵǸ� �����ϰ� ī���� �ʱ�ȭ
			cnt = 1;
			result = sum;
		}
		else if (result == sum) cnt++;	// ���� �ּҰ��� ������ ī����
	}
	printf("%d %d\n", result, cnt);
}