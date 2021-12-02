#include<iostream>
#include<algorithm>
#define endl "\n"
using namespace std;

int lis[100001];		// lis�� �Ǵ� ���� �� ��ü�� �迭�� ����
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int size = 0;
	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		if (size == 0 || lis[size - 1] < x) {	// 0�̸� ������ �־�� �ǰ� ������ ���ں��� ũ�� �� ������ �ֱ�
			lis[size++] = x;		// �ڿ��� ���� �ְ� size 1 �÷��ֱ�
		}
		else {
			int idx = lower_bound(lis, lis + size, x) - lis;	// ���� ���� ���� �� �ε��� ��ġ ã��. ������ �� ���� ���ų� ū ������ �ּҰ��� ��ü
			lis[idx] = x;
		}
	}	// end of input
	
	cout << N - size << endl;
}