#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> vec, sortVec;	//�� ã���� �� ���Ϳ� ������ ���� ���� ����
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(x);
		sortVec.push_back(x);
	}
	sort(sortVec.begin(), sortVec.end());
	sortVec.erase(unique(sortVec.begin(), sortVec.end()), sortVec.end());	//�ߺ��� �� ����
	
	int cnt;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		cnt += lower_bound(sortVec.begin(), sortVec.end(), vec[i]) - sortVec.begin();	//ã���� �ϴ� ������ ���� �ε��� ã��. �������� �̹Ƿ� �ε��� �� = ���� ������ ������ ��
		printf("%d ", cnt);
	}
	printf("\n");
}