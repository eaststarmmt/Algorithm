#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int map[1025][1025];

int pulling(int r, int c) {
	vector<int> input;
	for (int i = r; i < r + 2; i++) {
		for (int j = c; j < c + 2; j++) {	// 벡터로 일단 4개 넣음
			input.push_back(map[i][j]);
		}
	}
	sort(input.begin(), input.end());	// 오름차순 정렬 후 두번째로 큰 값 리턴
	return input[2];
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {	// 2로 나누는 연산에서 꼬일 위험 있으므로 1부터 시작
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	while (N >= 2) {	// 2보다 작아지면 2 X 2 행렬이 안되므로 2 이상일때만 반복

		for (int i = 2; i <= N; i += 2) {		// 2로 나눈 인덱스를 사용하기 때문에 2부터 시작
			for (int j = 2; j <= N; j += 2) {	// 2 X 2로 건너 뛰면서 나누기 때문에 2씩 증가
				map[i / 2][j / 2] = pulling(i -1, j -1);
			}
		}
		N /= 2;

	}
	
	printf("%d\n", map[1][1]);
}