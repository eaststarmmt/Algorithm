#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

struct Info {
	int a, b, c;
};

int damage[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 9, 3},
	{1, 3, 9}
};

int visited[64][64][64];
int N;
int scv[5];

int bfs() {
	queue<Info> Q;
	Q.push({ scv[0], scv[1], scv[2] });
	visited[scv[0]][scv[1]][scv[2]] = 1;

	while (!Q.empty()) {
		int a = Q.front().a;
		int b = Q.front().b;
		int c = Q.front().c;
		Q.pop();

		if (a == 0 && b == 0 && c == 0) {
			break;
		}

		for (int i = 0; i < 6; i++) {
			int na = max(0, a - damage[i][0]);
			int nb = max(0, b - damage[i][1]);
			int nc = max(0, c - damage[i][2]);

			if (visited[na][nb][nc] != 0) {
				continue;
			}
			Q.push({ na, nb, nc });
			visited[na][nb][nc] = visited[a][b][c] + 1;
		}	// end of for

	}	// end of while

	return visited[0][0][0] - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> scv[i];
	}	// end of for

	cout << bfs() << "\n";
	return 0;
}