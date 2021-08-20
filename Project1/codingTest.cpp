#include<stdio.h>
#include<algorithm>
using namespace std;

bool node[5000002];

int main() {
	// vector<int>[10000] 0부모 1오른쪽 2왼쪽
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
		
		if (node[now * 2]) {	// 왼쪽 자식 있는 경우
			now = now * 2;
		}
		else {					// 왼쪽 자식 없는 경우
			if (node[now * 2 + 1]) {	// 오른쪽 있는지 확인
				now = now * 2 + 1;
			}
			else {		// 자식 둘다 없음
				node[now] = false;	// 무한루프 막기 위해
				now = now / 2;
				
			}
		}
	}

}