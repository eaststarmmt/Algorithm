#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int N;
	scanf("%d", &N);
	vector<int> crane;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		crane.push_back(x);
	}	// end of for cranes input
	int m;
	scanf("%d", &m);
	vector<int> box;
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		box.push_back(x);
	}	// end of for boxes input

	sort(crane.begin(), crane.end(), cmp);	// �ڽ�, ũ���� �������� ����
	sort(box.begin(), box.end(), cmp);
	if (crane[0] < box[0]) {	// �ڽ��� ũ���� ��� ���Ժ��� ũ�� ����
		printf("-1\n");
		return 0;
	}
	int time = 0;
	while (m > 0) {	
		for (int i = 0; i < crane.size(); i++) {
			for (int j = 0; j < box.size(); j++) {
				if (crane[i] >= box[j]) {	// �ڽ� �ű� �� ������ ���� ũ��������
					box.erase(box.begin() + j);		// bool �迭�� ǥ���ϰ� continue �ϴ� �ͺ��� ����°� �� ����
					m--;	// ���� �ڽ� �� ī����
					break;
				}
			}	// end of for box
		}	// end of for crane 
		time++;
	}	// end of while
	printf("%d\n", time);
}