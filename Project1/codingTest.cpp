#include<stdio.h>
using namespace std;

bool node[5000002];

int main() {

	int N;
	scanf("%d", &N);
	node[1] = true;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(b != -1)
			node[b] = true;
		if (c != -1)
			node[c] = true;
	}
	int cnt = -1;
	int now = 1;
	while (true) {
		cnt++;
		if (now == N) {
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