#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int map[1001][1001];

int main() {

	int N;
	scanf("%d", &N);
	vector<int> width;

	for (int commend = 0; commend < N; commend++) {
		int c, r, w, h;
		scanf("%d %d %d %d", &c, &r, &w, &h);
		width.push_back(w * h);					// ���� �̸� ����
		for (int i = r; i < r + h; i++) {
			for (int j = c; j < c + w; j++) {
				if (map[i][j] != 0) {			// ��ġ�� �κ� ������ �򸮴� �κ��� ���� 1�� ����
					width[map[i][j] - 1]--;
				}
				map[i][j] = commend + 1;
			}
		}
	}
	
	for (auto i : width) {
		printf("%d\n", i);
	}
}