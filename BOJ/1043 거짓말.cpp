#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> party[51];
int parent[51];
	
int findParent(int x) {					// �θ� ������ ã�� �Լ�
	if (x == parent[x]) return x;
	return findParent(parent[x]);
}

void unionParent(int a, int b) {		// �ΰ��� �����ִ� �Լ�
	a = findParent(a);
	b = findParent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int know;
	int sum = m;
	vector<int> knowing;			// ������ �ƴ� �����
	scanf("%d", &know);	
	for (int i = 0; i < know; i++) {	// ���� �ƴ� ����� ����
		int x;
		scanf("%d", &x);
		knowing.push_back(x);
	}

	for (int i = 0; i < m; i++) {		// ��Ƽ ������ŭ ����
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {	// ��Ƽ ���� ����� �ο� ����
			int x;
			scanf("%d", &x);
			party[i].push_back(x);
		}
	}

	for (int i = 1; i <= n; i++) {	// �θ� �ڱ� �ڽ����� �ʱ�ȭ
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {		// ���� ��Ƽ�� �ִ� ����� ���Ͽ�
		for (int j = 1; j < party[i].size(); j++) {
			unionParent(party[i][0], party[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {		// ��Ƽ��ŭ ����
		for (int j = 0; j < knowing.size(); j++) {	// ��Ƽ�� �Ѹ�� ������ �ƴ� ����� �� �Ѹ��̶� �θ� ������ ������ �Ұ���
			if (findParent(knowing[j]) == findParent(party[i][0])) {
				sum--;
				break;
			}
		}
		
	}
	printf("%d\n", sum);
}