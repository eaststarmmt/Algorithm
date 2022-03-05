#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
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
	bool flag = false;	// 모든 노드를 다 지나고 가장 오른쪽을 확인해야 하므로 사용
	int visit = 1;		// 현재까지 한번이라도 지난 노드 개수
	int curD = 0;
	int maxD = 0;
	stack<int> st;		// 중위 순회는 가장 오른쪽에서 끝나기 때문에 그걸 표시하기 위해 스택 사용
	st.push(0);
	while (true) {
		if(!flag)		// 아직 모든 곳을 순회하지 못한 상태
			maxD = curD > maxD ? curD : maxD;	// 현재까지중 가장 오른쪽 체크
		else {
			if (curD == maxD) {		// 모든곳을 순회하고 가장 오른쪽에 있으면 종료
				printf("%d", cnt);
				return 0;
			}
		}
		cnt++;
		if (!check[now]) {		
			check[now] = true;
			visit++;			
		}
		if (visit == N) {		// 방문한 곳이 N이 되면 모든 노드 방문했다는 것으로 판단
			flag = true;
		}
		
		if (node[now][1] != 0) {	// 왼쪽 자식 있는 경우
			int x = node[now][1];
			node[now][1] = 0;
			now = x;
			st.push(--curD);		// 왼쪽 자식이므로 현재 위치를 왼쪽으로 이동후 그걸 스택에 저장
		}
		else {						// 왼쪽 자식 없는 경우
			if (node[now][2] != 0) {	// 오른쪽 있는지 확인
				int x = node[now][2];
				node[now][2] = 0;
				now = x;
				st.push(++curD);
			}
			else {		// 자식 둘다 없음
				
				int x = node[now][0];
				now = x;
				curD = st.top();	// 부모로 돌아갈때 왼쪽에서 왔는지 오른쪽에서 왔는지 판단하기가 힘듬
				st.pop();			// 그래서 스택 맨 위에 부모의 위치를 올려 놓음으로 해결
				
			}
		}
	}

}