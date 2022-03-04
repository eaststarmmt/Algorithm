#include<iostream>
#include<map>
#include<string>
#define endl "\n"
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; test++) {
		int N;
		cin >> N;
		map<string, int> cnt;
		for (int i = 0; i < N; i++) {
			string item, classification;
			cin >> item >> classification;
			cnt[classification]++;	// �з� ���� ���ڸ� ī����
		}

		int ans = 1;
		for (auto i : cnt) {
			ans *= i.second + 1;	// �з��� ��� �� ��� �� + 1 �ؼ� ����. ���� �� + ���Դ� ���
		}
		cout << ans - 1 << endl;	// �˸��� ��� ����� �ϹǷ� - 1
	}
}