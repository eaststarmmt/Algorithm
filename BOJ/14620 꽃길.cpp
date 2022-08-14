#include <iostream>
#include <algorithm>
using namespace std;

int N;
bool visited[14][14];
int map[14][14];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int res = 1e9;

bool check(int r, int c) {
	if(visited[r][c]) {
		return false;
	}
	
	for(int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(visited[nr][nc]) {
			return false;
		}
	}
	return true;
}

int flower(int r, int c) {
	int sum = map[r][c];
	visited[r][c] = true;
	for(int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		sum += map[nr][nc];
		visited[nr][nc] = true;
	}
	return sum;
}

void remove_flower(int r, int c) {
	visited[r][c] = false;
	
	for(int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		visited[nr][nc] = false;
	}
}

void permutation(int cnt = 0, int sum = 0) {
	if(cnt == 3) {
		res = min(sum, res);
		return;
	}	// end of if
	
	for(int i = 1; i < N - 1; i++) {
		for(int j = 1; j < N - 1; j++) {
			if(check(i, j)) {
				permutation(cnt + 1, sum + flower(i, j));
				remove_flower(i, j);
			}			
		}	// end of for j
	}	// end of for i
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	
	permutation();
	cout << res << "\n";
	return 0;
}