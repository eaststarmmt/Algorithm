#include<cstdio>
#include<vector>
#include<algorithm>
#define INF 1e9
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {	// ���� �ð� �������� ��������
	return a.second > b.second;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<pair<int, int>> work;

	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		work.push_back({ x, y });
	}

	sort(work.begin(), work.end(), cmp);

	int early = INF;	// �ƴ� ���� �Ϸ簡 24�ñ��� ���� ���� 100�� �ð����� ������ָ� �� ������ �Ϸ��� �������� �Ϸ簡 ���� ���� ��ü�� ���� �ΰ��� ���� ����
						// ��ú��� �����ؾ� �Ǵ��� ����� ���� ����
	for (int i = 0; i < work.size(); i++) {
		if (early > work[i].second) early = work[i].second;		// early ���� �����ð����� ũ�ٸ� �ǹ� ���� ��Ȳ. early�� �����ð����� �����ش�
		early -= work[i].first;					// early�� �ɸ��� �ð���ŭ ������ ����
	}
	if (early < 0) printf("%d\n", -1);			// 0���� ������ �־��� �ð��� �Ұ��� �ϰų� ������ ��ġ�� ��Ȳ
	else printf("%d\n", early);					// �� ���� ��� �������

}