#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

//bool node[5000002];
int node[100001][3];
bool check[5000001];	// �ܼ� ī���� ��

int main() {
	// vector<int>[10000] 0�θ� 1������ 2����
	int N;
	scanf("%d", &N);
	int lastLeaf = 0;
	
	for (int i = 0; i < N; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (b != -1)
			node[a][1] = b;
		if (c != -1)
			node[a][2] = c;
		if (b != -1)
			node[b][0] = a;
		if (c != -1)
			node[c][0] = a;
	}
	int cnt = -1;
	int now = 1;
	check[now] = true;
	int visit = 1;
	while (true) {
		cnt++;
		if (!check[now]) {		
			check[now] = true;
			visit++;
		}
		if (visit == N) {		// �湮�� ���� N�� �Ǹ� ������ �湮�� �ߴٴ°����� ������
			printf("%d", cnt);
			return 0;
		}
		
		if (node[now][1] != 0) {	// ���� �ڽ� �ִ� ���
			int x = node[now][1];
			node[now][1] = 0;
			now = x;
		}
		else {						// ���� �ڽ� ���� ���
			if (node[now][2] != 0) {	// ������ �ִ��� Ȯ��
				int x = node[now][2];
				node[now][2] = 0;
				now = x;
			}
			else {		// �ڽ� �Ѵ� ����
				int x = node[now][0];
			
				now = x;
				
			}
		}
	}

}