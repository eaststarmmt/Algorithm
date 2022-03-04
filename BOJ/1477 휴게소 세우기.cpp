#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int N, M, L;
vector<int> rest;

int divideCon(int start, int end) {
	
	int min = (int)1e9;

	while (start <= end) {
		int cnt = 0;
		int mid = (start + end) / 2;	// mid ���ݸ��� �ްԼ� �ϳ��� ���� ����. �� mid�� ������ �ִ밪��

		for (int i = 1; i < rest.size(); i++) {
			int dist = rest[i] - rest[i - 1];	// �ްԼ� ����
			cnt += dist / mid;		// ex mid�� 70�̰� ������ 144�̸� 2�� ������ ����
			if (dist % mid == 0) cnt--;	// ex mid 70 ���� 140�϶� 2�� ������ �������� ��ħ. �׷��� -1
		}

		if (cnt > M) start = mid + 1;
		else {
			end = mid - 1;
			min = mid < min ? mid : min;	// cnt�� ���� ��쿡�� M�� ���������� ���� ũ�� ����. �׷��� �̶� �ּҰ��� �����ߵ�
		}
			
	}
	return min;
}

int main() {
	scanf("%d %d %d", &N, &M, &L);

	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		rest.push_back(x);
	}
	rest.push_back(0);	// ���� �տ� �ްԼ� ���� ���ϴ� �뵵
	rest.push_back(L);	// ������ �ްԼҿ� ��ӵ����� ���� ���� ���ϴ� �뵵
	sort(rest.begin(), rest.end());	// �̺�Ž���� ���� ����

	printf("%d\n", divideCon(1, L - 1));	// ������ ���� �ȵǹǷ� L - 1
}