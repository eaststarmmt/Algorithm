#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[304][304], cnt[304]; // �ε���, ����
int N, M, K, T, a, b;
vector<pair<int, int>> v;   // �ο�, ����. ������ ���� ����

int go(int here, int num, int prev) {   // ���� �ο�, �ε���, ������ ���� �ο�
	if (here == v.size()) return 0;  // ������ �ε��� ������ �� ��� ����
	// �޸������̼�
	int &ret = dp[here][num];
	if (ret) return ret;

	int cost = max(0, T - v[here].first);   // T�� ���߱� ���� �ּ� �ο�.
	int real_cost = prev - cost >= 0 ? 0 : cost - prev; // ������ ���� �� �ο��� �� ������ ������ �ʿ� ����, ������ �ʿ��� ��ŭ ����

	if (num - real_cost >= 0) {  // �ʿ��� �ο��� ����� �ִ� ���
		// ���� ������ �ο��� �����ϴ� ���� �������� �ʴ� ��� �� �� ū ��� ���� �� ����
		return ret = max(go(here + 1, num - real_cost, cost) + v[here].second, go(here + 1, num, 0));
	}
	else return ret = go(here + 1, num, 0);   // ������ �Ұ����ϹǷ� �̹� ���� �ǳʶٰ� ���� �������� �Ѿ��

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K >> T;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		for (int j = a; j < b; j++) {
			cnt[j] = min(T, ++cnt[j]);  // T�� �Ѿ�� �ǹ� ���� ����
		}   // end of for cnt
	}   // end of for M

	int time = 1;   // ������ ����
	int num = cnt[1];   // �ο�

	for (int i = 2; i <= N; i++) {
		if (num != cnt[i]) {     // �ο��� �޶������Ƿ� �ٸ� �������� �ǹ�. �������� ���Ϳ� ����
			v.push_back({ num, time });
			num = cnt[i];
			time = 0;
		}
		time++;
	}   // end of for i

	v.push_back({ num, time });

	cout << go(0, K, 0) << '\n';
	return 0;
}