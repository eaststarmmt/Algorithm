#include<stdio.h>
#include<cstring>
using namespace std;

bool visited[11][31];
int l[11][31];
int N, M, H;

void addLine(int cnt) {
	if (cnt > N) return;
	if (cnt != 0) {
		// TODO: 확인하는 부분
	}
	
}

int main() {
	scanf("%d %d %d", &N, &M, &H);

	for (int i = 0; i < M; i++) {	// input
		int a, b;
		scanf("%d %d", &a, &b);
		l[a][b] = 1;
	}

	addLine(0);
	
}