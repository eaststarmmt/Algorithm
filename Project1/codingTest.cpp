#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> tower;	
	
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		tower.push_back(x);
	}
	stack<pair<int, int>> result;	// ��, �ε��� ����
	result.push({ tower[0], 1 });	// ù��° ���� ������ Ǫ��
	printf("%d ", 0);				// ó������ ������ 0 ���
	for (int i = 1; i < n; i++) {
		bool fail = false;			// ��� ���ÿ� �ִ� ������ ū ��� üũ�ϱ� ���� �÷���
		while (!result.empty()) {	// ������ �������� ��� ��
			if (tower[i] > result.top().first) {	// top�� �� ���� �� ū ���
				result.pop();						// ���� �� �񱳸� ���� ���ÿ��� ����
				fail = true;
			}
			else {
				printf("%d ", result.top().second);		// top�� �� ũ�� top�� �ִ� Ÿ�� �ε��� ���
				result.push({ tower[i], i + 1 });		// ���� tower�� ���ÿ� �ø���
				fail = false;
				break;
			}
		}
		if (fail) {										// ���þȿ� ��� ������ �� ū ���
			printf("%d ", 0);							// 0 ����ϰ� ���ÿ� �ֱ�
			result.push({ tower[i], i + 1 });
		}
	}
}