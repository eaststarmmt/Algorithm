#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

int N;
int map[21][21];
bool selected[21];
int res = 1e9;

void comb(vector<int> star, int start) {
	if (star.size() == N / 2) {
		// �� ���ϱ�
		vector<int> link;
		for (int i = 1; i <= N; i++) {	// ��ũ�� ��� ����
			if (!selected[i]) 
				link.push_back(i);
		}	// end of link team

		int start_stat = 0;
		int link_stat = 0;

		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				start_stat += map[star[i]][star[j]];
				link_stat += map[link[i]][link[j]];
			}
		}	// end of stat calc

		int dif = abs(start_stat - link_stat);
		res = dif < res ? dif : res;
	}

	for (int i = start; i <= N; i++) {
		selected[i] = true;	// ��ŸƮ ���� �����ֵ� ǥ��
		star.push_back(i);	// ��ŸƮ ���� �ֱ�
		comb(star, i + 1);
		star.pop_back();	// ��ŸƮ ������ ���� ���� ����
		selected[i] = false;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}	// end of input
	vector<int> star;
	comb(star, 1);
	printf("%d\n", res);
}