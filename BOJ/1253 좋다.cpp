#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	vector<long long> num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long x;
		cin >> x;
		num.push_back(x);
	}	// �Է°� ���Ϳ� ����

	sort(num.begin(), num.end());
	int cnt = 0;
	for (int i = 0; i < N; i++) {	// �̺�Ž�� ���� ����ϰ� �̿�. i��° �� �Ǵ��� ã��
		int start = 0, end = N - 1;
		while (start < end) {		// ������ �ι� �� ���ؼ� end�� Ŭ ���� ��� ����
			long long sum = num[start] + num[end];
			if (sum == num[i]) {
				if (start != i && end != i) {
					cnt++;
					break;
				}
				else if (start == i)	// start�� �����Ƿ� ���������� �̵�
					start++;
				else if (end == i)		// start�� �����Ƿ� �������� �̵�
					end--;
			}
			else if (sum < num[i])	// ���� �Ǿ� �����Ƿ� ���� ��� ���� �����͸� ���������� �̵�
				start++;
			else					// Ŭ ��� ������ �����͸� �������� ���ܼ� �� ����
				end--;
		}
	}
	cout << cnt << endl;
}