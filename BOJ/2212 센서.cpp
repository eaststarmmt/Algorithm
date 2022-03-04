#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	vector<int> sensor;
	for (int i = 0; i < N; i++) {	// ���� ��ġ �Է¹ޱ�
		int x;
		scanf("%d", &x);
		sensor.push_back(x);
	}

	sort(sensor.begin(), sensor.end());	// �������� ����
	vector<int> dis;
	for (int i = 1; i < N; i++) {
		dis.push_back(sensor[i] - sensor[i - 1]);	// ������ �Ÿ� �Է�
	}
	sort(dis.begin(), dis.end(), greater<int>());	// �������� ����
	int ans = 0;
	for (int i = K - 1; i < dis.size(); i++) {	// K�� ��ŭ ���������� ��ü ���� �ϹǷ� ū ������� K�� �����ϰ� ����
		ans += dis[i];
	}
	printf("%d\n", ans);
}