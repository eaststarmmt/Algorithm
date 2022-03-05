#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

bool breakDown[100001];

int main() {
	int N, K, B;
	scanf("%d %d %d", &N, &K, &B);
	for (int i = 1; i <= B; i++) {
		int x;
		scanf("%d", &x);
		breakDown[x] = true;		// �ʱ�ȭ ������ true�� ���峭�ɷ�. x�� ��ȣ�� ����
	}
	int result = 0;
	for (int i = 1; i <= K; i++) {
		if (!breakDown[i]) result++;	// 1 ~ K�� ���̿� ���峪�� ���� ��ȣ�� ���� ����
	}
	
	int cnt = result;

	if (N == K) {			// ������ �ƴ϶� N�� K�� ������ ���ѷ��� ���Ƽ� ����ó��
		printf("%d\n", K - result);
		return 0;
	}

	int start = K + 1;	// K + 1������ Ȯ��
	while (true) {
		if (!breakDown[start - K]) cnt--;	// ������ ���� �տ� ��ȣ���� �����־����� ���ֱ�
		if (!breakDown[start]) cnt++;		// ���� ���� ��ȣ���� ���� ������ ���ϱ�
		result = cnt > result ? cnt : result;	// ��ȣ���� ���� ���� ���� ��� ���
		start++;							// ������ �ε��� Ȯ��
		if (start == N + 1) break;			// N �� �Ѿ�� ���� ����Ƿ� Ż��
	}
	printf("%d\n", K - result);
}