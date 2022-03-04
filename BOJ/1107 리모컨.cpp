#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#define endl "\n"
using namespace std;
bool button[10] = { true,true,true,true,true,true,true,true,true,true };
int N, M;
int ans;
int len;	// ���� ��� ��ȯ���ִ� ��� ���
bool checked(int x) {
	string check = to_string(x);	// x�� ���ڿ��� ��ȯ
	len = check.length();
	for (int i = 0; i < check.size(); i++) {
		if (!button[check[i] - '0']) return false;	// �ϳ��� �ȴ����� �ǹ� ����
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int b;
		cin >> b;
		button[b] = false;
	}
	ans = abs(100 - N);	// ���̸�ŭ ������ ������ ���
	for (int i = 0; i <= 1000000; i++) {		// �ϴ� ��ư ������ġ �� ����. �̰� �� ū ���� ��� �������� ��춧���� 1000000 ��ƾ� ��. �� ū ���ڴ� �ؿ��� ���°� �� �����Ƿ� �ǹ� ����
		if (checked(i)) {	// i �� ��ư �������� Ȯ��
			int x = abs(N - i) + len;
			ans = x < ans ? x : ans;
		}
	}
	cout << ans << endl;
}