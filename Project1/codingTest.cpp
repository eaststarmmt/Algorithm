#include<stdio.h>
#include<set>
using namespace std;

int pizza[1000][1000];

int main() {
	int n, m;
	long long sum = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &pizza[i][j]);
			sum += pizza[i][j];
		}
	}
	set<pair<int, int>> view;	// �ߺ��� �����ϱ� ���� set ���
	int x, y, value;
	for (int i = 0; i < n; i++) {		// front ����
		x = 0;
		y = 0;
		value = 0;
		for (int j = 0; j < m; j++) {
			if (pizza[i][j] > value) {
				x = i;
				y = j;
				value = pizza[i][j];
			}
		}
		view.insert({ x, y });	// front�� ������ ���̴� �ֵ� ��ǥ�� ���� ����

		
	}

	for (int j = 0; j < m; j++) {
		x = 0;
		y = 0;
		value = 0;
		for (int i = 0; i < n; i++) {
			if (pizza[i][j] > value) {
				x = i;
				y = j;
				value = pizza[i][j];
			}
		}
		view.insert({ x, y });
	}
	for (auto iter = view.begin(); iter != view.end(); iter++) {	// set�� �ε����� �ƴ� �ּҷ� ����
		int i = (*iter).first;
		int j = (*iter).second;
		sum -= pizza[i][j];		// �ش� ��ǥ�� ���� ����
	}
	printf("%lld", sum);	// int ���� �Ѿ�� long long ����
}