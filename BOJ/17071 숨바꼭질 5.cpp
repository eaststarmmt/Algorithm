#include <iostream>
#include <queue>
#define MAX 500000
using namespace std;

int N, K;
int visited[2][500004];	// 이동은 홀짝으로 구분해서 체크. 홀짝이 맞으면 앞뒤로 한칸씩 와리가리 하면서 결국 가는게 가능
bool flag;
int turn = 1;

void bfs() {
	queue<int> Q;
	Q.push(N);
	visited[0][N] = 1;
	while (!Q.empty()) {
		K += turn;				// 동생 먼저 이동
		if (K > MAX) {
			return;
		}
		if (visited[turn % 2][K]) {	// 이미 수빈이가 홀짝 맞는 상황에서 간 적 있으면 만날 수 있음
			flag = true;
			return;
		}
		int size = Q.size();
		for (int i = 0; i < size; i++) {	// 시간 단위로 계산하기 위해 현 시간에 큐에 들어있는 만큼 크기 잡음
			int x = Q.front();
			Q.pop();
			for (int next : {x - 1, x + 1, 2 * x}) {
				if (next < 0 || next > MAX || visited[turn % 2][next]) {
					continue;
				}
				if (next == K) {
					flag = true;
					return;
				}

				visited[turn % 2][next] = visited[(turn + 1) % 2][x] + 1;
				Q.push(next);
			}	// end of for next
		}	// end of for size
		turn++;
	}	// end of while Q
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	if (N == K) {
		cout << 0 << "\n";
		return 0;
	}
	bfs();
	if (flag) cout << turn << "\n";
	else cout << -1 << "\n";
	return 0;
}