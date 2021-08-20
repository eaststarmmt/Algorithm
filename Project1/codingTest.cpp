#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

//bool node[5000002];
int node[100001][3];
bool check[5000001];	// 단순 카운팅 용

int main() {
	// vector<int>[10000] 0부모 1오른쪽 2왼쪽
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
		if (visit == N) {		// 방문한 곳이 N이 되면 마지막 방문을 했다는것으로 간주함
			printf("%d", cnt);
			return 0;
		}
		
		if (node[now][1] != 0) {	// 왼쪽 자식 있는 경우
			int x = node[now][1];
			node[now][1] = 0;
			now = x;
		}
		else {						// 왼쪽 자식 없는 경우
			if (node[now][2] != 0) {	// 오른쪽 있는지 확인
				int x = node[now][2];
				node[now][2] = 0;
				now = x;
			}
			else {		// 자식 둘다 없음
				int x = node[now][0];
			
				now = x;
				
			}
		}
	}

}