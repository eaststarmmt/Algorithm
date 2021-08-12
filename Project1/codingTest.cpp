#include<stdio.h>
#include<algorithm>
using namespace std;

int durability[8];
int weight[8];
int result;
int N;

void permutation(int now, int broken) {
	
	result = max(result, broken);

	if (now == N) return;	// ������ �� �غ� ���

	for (int i = 0; i < N; i++) {	// now�� ����ִ� ���, i�� ���� ���

		if (i == now || durability[i] <= 0) continue;	// ���� ����ִ� ����ϰ� ���� ����� ��ġ�ų� �������� ����� ���������� ����
		if (durability[now] <= 0) {						// ���� ���� ����� ���������� ���� ����� ������ �ѱ�� ����
			permutation(now + 1, broken);
			return;
		}
		int cnt = 0;
		durability[i] -= weight[now];				// ����� ���� ��� ī����
		if (durability[i] <= 0) 
			cnt++;
		durability[now] -= weight[i];
		if (durability[now] <= 0) 
			cnt++;

		permutation(now + 1, broken + cnt);
		durability[i] += weight[now];				// ���� ���� ��ȸ�� ���� �������´�
		durability[now] += weight[i];
		
	}
}


int main() {
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &durability[i], &weight[i]);
	}

	permutation(0, 0);
	printf("%d", result);
}