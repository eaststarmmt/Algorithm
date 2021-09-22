#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {	// ������ �ð��� ���� ������ ����
	if (a.second == b.second) return a.first < b.first;	// ������ �ð��� ���� ��� ���۽ð��� ���� ȸ�ǰ� ���� �;� ��
	return a.second < b.second;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<pair<int, int>> input;
	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		input.push_back({ x, y });
	}

	sort(input.begin(), input.end(), cmp);	
	int cnt = 0;
	int nowWork = -1;	// ���� ȸ�� ������ �ð�
	for (int i = 0; i < input.size(); i++) {
		if (input[i].first >= nowWork) {	// ȸ�� ���۽ð��� ������ �ð����� ũ�ų� �������
			nowWork = input[i].second;	// ȸ�ǰ� ����
			cnt++;			// ī����
		}
	}
	printf("%d\n", cnt);
}