#include<stdio.h>
#include<vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int test = 0; test < n; test++) {
		int m;
		scanf("%d", &m);
		vector<int> left, right;
		int sum = 0;
		for (int i = 0; i < m; i++) {
			int x;
			scanf("%d", &x);
			left.push_back(x);
		}
		for (int i = 0; i < m; i++) {
			int x;
			scanf("%d", &x);
			right.push_back(x);
		}
		for (int i = 0; i < left.size() - 1; i++) {			
			for (int j = i + 1; j < left.size(); j++) {		
				if (left[i] + 500 == left[j]) {				// �չ����� �޹������� 500�� �ڿ� ���� 
					for (int k = 0; k < right.size(); k++) {	// �޹��� ���� ���� �����ʿ� 500�� �ڿ� ����
						if (left[j] + 500 == right[k]) sum++;
					}
				}
			}
		}
		printf("%d\n", sum);
	}

}