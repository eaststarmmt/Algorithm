#include<iostream>
#include<algorithm>
#define INF 1e9;

using namespace std;

int a[3][3];
int res = INF;

int check(int a, int b, int c) {
	int mid = a + b + c - max(a, max(b, c)) - min(a, min(b, c));  // 중간 값 잡기
	return abs(mid - a) + abs(mid - b) + abs(mid - c);  // 중간값에서 뺀 차이 만큼의 변화로 평평하게 만들 수 있음
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		res = min(res, check(a[i][0], a[i][1], a[i][2]));  // 행 단위
		res = min(res, check(a[0][i], a[1][i], a[2][i]));  // 열 단위
	}

	cout << res << '\n';
	return 0;
}