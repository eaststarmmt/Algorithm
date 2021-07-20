#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<pair<int, int>> jam;	
	
	for (int i = 0; i < n; i++) {
		int m, v;
		scanf("%d %d", &m, &v);
		jam.push_back({ m , v });
	}

	vector<int> bag;
	
	for (int i = 0; i < k; i++) {
		int c;
		scanf("%d", &c);
		bag.push_back(c);
	}

	sort(jam.begin(), jam.end());	// ���� ���Է� �������� ����
	sort(bag.begin(), bag.end());	// ���� ���� ������������ ����
	long long sum = 0;
	
	priority_queue<int> value;
	int idx = 0;	// �켱���� ť�� ���� �ε��� �˱� ����
	// ������ ���������̹Ƿ� ������ �־��� �������� �ٽ� �غ��� �ʾƵ� ��
	// ���� �ε������� �ؼ� �̹� ���� ������ ���� ���·� �켱���� ť�� ������ �� ����
	// ���� ���濡 ���� �� �ִ� ���� ��� ������ �ϳ��ϳ� ä������ ���
	for (int i = 0; i < k; i++) {
		while (idx < n && jam[idx].first <= bag[i]) {	// for�ϰ� if ���� �ð��ʰ� ���� while�� �ѹ��� �ؾߵ�
			value.push(jam[idx].second);
			idx++;
		}
		if (!value.empty()) {		// value ��������� double free �߻��ϹǷ�
			sum += value.top();
			value.pop();
		}
	}
	printf("%lld", sum);

}