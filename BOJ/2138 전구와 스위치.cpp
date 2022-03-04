#include<iostream>
#include<string>
#include<algorithm>
#define INF 1e9
using namespace std;

int n;
string a1, a2, b;

void reverse(int x) {
	for (int i = x - 1; i < x + 2; i++) {
		if (i == n) break;
		if (i == -1) continue;
		if (a1[i] == '0') a1[i] = '1';
		else a1[i] = '0';
	}
}

void reverse2(int x) {
	for (int i = x - 1; i < x + 2; i++) {
		if (i == n) break;
		if (i == -1) continue;
		if (a2[i] == '0') a2[i] = '1';
		else a2[i] = '0';
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> a1 >> b;
	a2 = a1;
	int cnt1 = 1, cnt2 = 0;	// ù��° ������ ���������Ƿ� 1�� ����
	reverse(0);	// ù��° ������ ������ ���
	for (int i = 1; i < n; i++) {
		if (a1[i - 1] != b[i - 1]) {	// ������ ���ؼ� ���縦 ������ ����
			reverse(i);		// �����Ÿ� ������ ������ ������ ����
			cnt1++;
		}
	}
	for (int i = 1; i < n; i++) {	// ù��° �ȴ��� ���
		if (a2[i - 1] != b[i - 1]) {
			reverse2(i);
			cnt2++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (a1[i] != b[i]) {
			cnt1 = INF;			// �ٸ��� �����ؾ� �ϹǷ� ���Ѵ� �������
		}
		if (a2[i] != b[i]) {
			cnt2 = INF;
		}
	}
	if (cnt1 == INF && cnt2 == INF) cout << -1 << "\n";
	else cout << min(cnt1, cnt2) << "\n";
}