#include<iostream>
#include<cmath>
#define endl "\n"
using namespace std;

int N, res;
int col[16]; // col[i] = x	i 행의 x 열에 퀸 있음
bool checked(int r) {
	for (int i = 1; i < r; i++) {
		if(col[i] == col[r] || abs(col[i] - col[r]) == r - i)	// 같은 열에 있거나 대각 관계
			return false;
	}
	return true;
}

void nQueen(int r) {
	if (r == N + 1) {
		res++;
		return;
	}
	for (int i = 1; i <= N; i++) {
		col[r] = i;
		if (checked(r)) {
			nQueen(r + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	nQueen(1);
	cout << res << endl;
}