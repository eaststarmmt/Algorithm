#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> time;	// ���۽ð� �� �ð� ������ ����
	priority_queue<int, vector<int>, greater<int>> endTime;	// �� �ð��� ������ �켱���� ť
														// ���� ������ �ð� ������ �����ϱ� ���� min heap ���� ����
	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		time.push_back({ x, y });
	}
	
	sort(time.begin(), time.end());		// ���۽ð� �������� �������� ����
	endTime.push(time[0].second);		// ���� ���� ������ ������ ������ �ð� push

	for (int i = 1; i < time.size(); i++) {
		if (endTime.top() <= time[i].first) endTime.pop();	// ���� ����� ���� ���� ������ �ð����� ���۽ð��� �� �����ų� ������ 
															// ����� ���� pop. ������ �ڿ��� push�ؼ� ������ ����
		endTime.push(time[i].second);	// ���� ������ �ð� push. ������ �ð��� ���� ���� ���ǰ� top�� �־ ������ ���� ������ ��������
	}

	printf("%d\n", endTime.size());	// �켱���� ť���� ���ǽð��� ��ġ�� �ֵ��� pop���� ����ä�� ��������. �� ���ǽ� ������ ��
}