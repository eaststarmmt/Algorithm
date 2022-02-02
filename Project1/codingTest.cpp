#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

struct Grit {
	int a, b, c;
};

bool visited[1501][1501];	// 모든 돌이 한쪽으로 몰빵되는 최악의 상황이 1500임. 앞에 두개만 비교하면 나머지 숫자는 어차피 정해져 있다는 개념으로 접근

void bfs(Grit grit) {
	queue<Grit> Q;
	Q.push(grit);
	visited[grit.a][grit.b] = true;	// 앞이 작은 값 뒤가 큰 값
	visited[grit.a][grit.c] = true;
	visited[grit.b][grit.c] = true;
	int ngrit[3] = { 0 };	// 그냥 sort용 이거 안쓰는 방법 알면 좀 가르쳐주세요....

	while (!Q.empty()) {
		Grit g = Q.front();
		Q.pop();
		if (g.a == g.b && g.a == g.c) {	// 모두 같으면 거기서 종료
			printf("1\n");
			return;
		}
		
		if (g.a != g.b) {	// a b 다른경우
			ngrit[2] = g.c;
			if (g.a > g.b) {
				ngrit[0] = g.a - g.b;
				ngrit[1] = g.b * 2;
			}
			else {
				ngrit[0] = g.a * 2;
				ngrit[1] = g.b - g.a;
			}
			sort(ngrit, ngrit + 3);	// 세 개 밖에 없어서 sort 사용함
			if (!visited[ngrit[0]][ngrit[1]]) {	// 방문한 적 없을 때만
				Q.push({ ngrit[0], ngrit[1], ngrit[2] });
				visited[ngrit[0]][ngrit[1]] = true;
			}
		}

		if (g.a != g.c) {	// a c 다른경우
			ngrit[1] = g.b;
			if (g.a > g.c) {
				ngrit[0] = g.a - g.c;
				ngrit[2] = g.c * 2;
			}
			else {
				ngrit[0] = g.a * 2;
				ngrit[2] = g.c - g.a;
			}
			sort(ngrit, ngrit + 3);	// 세 개 밖에 없어서 sort 사용함
			if (!visited[ngrit[0]][ngrit[1]]) {	// 방문한 적 없을 때만
				Q.push({ ngrit[0], ngrit[1], ngrit[2] });
				visited[ngrit[0]][ngrit[1]] = true;
			}
		}

		if (g.b != g.c) {	// b c 다른경우
			ngrit[0] = g.a;
			if (g.b > g.c) {
				ngrit[1] = g.b - g.c;
				ngrit[2] = g.c * 2;
			}
			else {
				ngrit[1] = g.b * 2;
				ngrit[2] = g.c - g.b;
			}
			sort(ngrit, ngrit + 3);	// 세 개 밖에 없어서 sort 사용함
			if (!visited[ngrit[0]][ngrit[1]]) {	// 방문한 적 없을 때만
				Q.push({ ngrit[0], ngrit[1], ngrit[2] });
				visited[ngrit[0]][ngrit[1]] = true;
			}
		}
	}
	printf("0\n");
}

int main() {
	int input[3];
	scanf("%d %d %d", &input[0], &input[1], &input[2]);
	sort(input, input + 3);
	Grit grit = { input[0], input[1], input[2] };
	bfs(grit);
}