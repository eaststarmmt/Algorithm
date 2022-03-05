#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
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
	bool flag = false;	// ��� ��带 �� ������ ���� �������� Ȯ���ؾ� �ϹǷ� ���
	int visit = 1;		// ������� �ѹ��̶� ���� ��� ����
	int curD = 0;
	int maxD = 0;
	stack<int> st;		// ���� ��ȸ�� ���� �����ʿ��� ������ ������ �װ� ǥ���ϱ� ���� ���� ���
	st.push(0);
	while (true) {
		if(!flag)		// ���� ��� ���� ��ȸ���� ���� ����
			maxD = curD > maxD ? curD : maxD;	// ��������� ���� ������ üũ
		else {
			if (curD == maxD) {		// ������ ��ȸ�ϰ� ���� �����ʿ� ������ ����
				printf("%d", cnt);
				return 0;
			}
		}
		cnt++;
		if (!check[now]) {		
			check[now] = true;
			visit++;			
		}
		if (visit == N) {		// �湮�� ���� N�� �Ǹ� ��� ��� �湮�ߴٴ� ������ �Ǵ�
			flag = true;
		}
		
		if (node[now][1] != 0) {	// ���� �ڽ� �ִ� ���
			int x = node[now][1];
			node[now][1] = 0;
			now = x;
			st.push(--curD);		// ���� �ڽ��̹Ƿ� ���� ��ġ�� �������� �̵��� �װ� ���ÿ� ����
		}
		else {						// ���� �ڽ� ���� ���
			if (node[now][2] != 0) {	// ������ �ִ��� Ȯ��
				int x = node[now][2];
				node[now][2] = 0;
				now = x;
				st.push(++curD);
			}
			else {		// �ڽ� �Ѵ� ����
				
				int x = node[now][0];
				now = x;
				curD = st.top();	// �θ�� ���ư��� ���ʿ��� �Դ��� �����ʿ��� �Դ��� �Ǵ��ϱⰡ ����
				st.pop();			// �׷��� ���� �� ���� �θ��� ��ġ�� �÷� �������� �ذ�
				
			}
		}
	}

}