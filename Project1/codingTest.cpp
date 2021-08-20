#include<stdio.h>
#include<algorithm>
using namespace std;

bool node[5000002];

int main() {
	// vector<int>[10000] 0�θ� 1������ 2����
	int N;
	scanf("%d", &N);
	int lastLeaf = 0;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		node[a] = true;
		lastLeaf = max(lastLeaf, a);
	}
	int cnt = -1;
	int now = 1;
	while (true) {
		cnt++;
		if (now == lastLeaf) {
			printf("%d", cnt);
			return 0;
		}
		
		if (node[now * 2]) {	// ���� �ڽ� �ִ� ���
			now = now * 2;
		}
		else {					// ���� �ڽ� ���� ���
			if (node[now * 2 + 1]) {	// ������ �ִ��� Ȯ��
				now = now * 2 + 1;
			}
			else {		// �ڽ� �Ѵ� ����
				node[now] = false;	// ���ѷ��� ���� ����
				now = now / 2;
				
			}
		}
	}

}