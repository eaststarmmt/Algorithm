#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	int T;
	scanf("%d", &T);
	
	for (int test = 1; test <= T; test++) {
		int N;
		scanf("%d", &N);
		vector<int> vec1, vec2;
		vec1.push_back(1);				
		printf("#%d\n", test);
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < i; j++) {
				if (j == 0) {				// ù �ε����� ������ 0�� ��
					printf("%d ", 1);
					vec2.push_back(1);		// �����ٿ��� ����ϱ� ���� ����
				}
				else if (j == i - 1) {		// ������ �ε����� ������ 0�� ��
					printf("%d ", 1);
					vec2.push_back(1);
				}
				else {						// �߰��� ������ ������ ���� ���� (�ٷ� �� �ε��� �� + ���� �ε�����)
					printf("%d ", vec1[j - 1] + vec1[j]);
					vec2.push_back(vec1[j - 1] + vec1[j]);
				}
			}
			vec1.assign(vec2.begin(), vec2.end());	// �̹��ٿ��� ���� ���� vec2�� ����
			vec2.clear();							// ���� �ٿ��� ���� �ޱ� ���� vec2�� ���
			printf("\n");
		}
	}
}