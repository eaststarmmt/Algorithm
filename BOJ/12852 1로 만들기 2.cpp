#include<iostream>
#include<algorithm>
#define endl "\n"
using namespace std;
int dp[1000001];
int seq[1000001];	// ������ ������ �迭
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;	// �켱 i - 1 �����ڰ� ����
		seq[i] = i - 1;			// i ���忡�� ���� ������ i - 1
		if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) { // i �� 3���� ������ ���°�� 
			dp[i] = dp[i / 3] + 1;	
			seq[i] = i / 3;	// i / 3�� ���� �������� ����
			
		}
		if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {	// 3�� ����
			dp[i] = dp[i / 2] + 1;
			seq[i] = i / 2;
		}
	}
	cout << dp[N] << endl;	// ���� Ƚ�� ���
	while (N != 0) {		// 1�� ������ 0�̹Ƿ� 0�� �ɶ����� ��� ����
		cout << N << ' ';	// N ����ϰ�
		N = seq[N];			// N ���� �ܰ�� ����
	}
}