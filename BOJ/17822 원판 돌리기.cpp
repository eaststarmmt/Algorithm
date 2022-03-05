#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int N, M, T;
vector<vector<int>> circle(50);
int sum, res, cnt;

bool same[50][50];

void remove(bool flag) {
	if (flag) {				// 지울게 있는 경우
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (same[i][j]) {
					sum -= circle[i][j];
					circle[i][j] = 0;
					cnt--;
				}
			}
		}
	}
	else {	// 지울게 없는 경우
		double avg = (double)sum / cnt;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (circle[i][j] == 0) continue;
				if (circle[i][j] > avg) {
					circle[i][j]--;
					sum--;
				}
				else if(circle[i][j] < avg){
					circle[i][j]++;
					sum++;
				}

			}
		}
	}
}

void adjacent() {	// 인접 배열 비교
	memset(same, false, sizeof(same));
	bool flag = false;
	for (int i = 0; i < N; i++) {	// 옆에 비교
		for (int j = 1; j < M; j++) {
			if (circle[i][j] == 0 && circle[i][j - 1] == 0) continue;		// 둘다 0인 경우에 같다고 판단되는거 대비해서 0을 건너 뜀
			if ((circle[i][j] == circle[i][j - 1])) {
				same[i][j] = true;
				same[i][j - 1] = true;
				flag = true;
			}
		}
		if (circle[i][0] == 0 && circle[i][M - 1] == 0) continue;
		if (circle[i][0] == circle[i][M - 1]) {
			same[i][0] = true;
			same[i][M - 1] = true;
			flag = true;
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 1; j < N; j++) {
			if (circle[j][i] == 0 && circle[j - 1][i] == 0) continue;
			if ((circle[j][i] == circle[j - 1][i])) {
				same[j][i] = true;
				same[j - 1][i] = true;
				flag = true;
			}
		}
	}
	remove(flag);

}

void turn(int x, int d, int k) {	// x의 배수 d 방향 k칸
	for (int rot = 0; rot < k; rot++) {		// 이동 칸 만큼 반복
		for (int i = x - 1; i < N; i += x) {	// x의 배수인 원판들 회전
			int temp = circle[i][0];
			if (d == 0) {	// 시계방향
				for (int j = M - 1; j >= 1; j--) {
					circle[i][(j + 1) % M] = circle[i][j];
				}
				circle[i][1] = temp;
			}
			else {
				for (int j = 0; j < M - 1; j++) {
					circle[i][j] = circle[i][j + 1];
				}
				circle[i][M - 1] = temp;
			}
		}
	}

	adjacent();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> T;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int x;
			cin >> x;
			circle[i].push_back(x);
			sum += x;
			cnt++;
		}
	}

	for (int i = 0; i < T; i++) {
		int x, d, k;
		cin >> x >> d >> k;
		turn(x, d, k);
	}
	cout << sum << "\n";
}