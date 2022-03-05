#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int map[1025][1025];

int pulling(int r, int c) {
	vector<int> input;
	for (int i = r; i < r + 2; i++) {
		for (int j = c; j < c + 2; j++) {	// ���ͷ� �ϴ� 4�� ����
			input.push_back(map[i][j]);
		}
	}
	sort(input.begin(), input.end());	// �������� ���� �� �ι�°�� ū �� ����
	return input[2];
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {	// 2�� ������ ���꿡�� ���� ���� �����Ƿ� 1���� ����
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	while (N >= 2) {	// 2���� �۾����� 2 X 2 ����� �ȵǹǷ� 2 �̻��϶��� �ݺ�

		for (int i = 2; i <= N; i += 2) {		// 2�� ���� �ε����� ����ϱ� ������ 2���� ����
			for (int j = 2; j <= N; j += 2) {	// 2 X 2�� �ǳ� �ٸ鼭 ������ ������ 2�� ����
				map[i / 2][j / 2] = pulling(i -1, j -1);
			}
		}
		N /= 2;

	}
	
	printf("%d\n", map[1][1]);
}