#include<iostream>
#include<algorithm>
#define endl "\n"
#define INF 1e9
using namespace std;

int dp[1001][3];
int house[10001][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> house[i][0] >> house[i][1] >> house[i][2];
	}
	
	for (int i = 0; i < 3; i++) {	// 1���� �ּҰ��� �ڱ��ڽ�
		dp[1][i] = house[1][i];
	}

	int res = INF;
	
	for (int first = 0; first < 3; first++) {
		
		for (int i = 0; i < 3; i++) {
			if (i == first) 
				dp[1][i] = house[1][i];		// ù������ ������ ��������� ���� ���� ���� ��. 
			else 
				dp[1][i] = INF;		// �ٸ��� ������� ���̴°� ����ؼ� ������ INF�� ���ϱ�
		}

		for (int i = 2; i <= N; i++) { // 1������ ������ �ʱ�ȭ �ص�
			dp[i][0] = house[i][0] + min(dp[i - 1][1], dp[i - 1][2]);	// 0�� ������� �� ���� 1�� 2�� ���� �� �ּҰ�
			dp[i][1] = house[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = house[i][2] + min(dp[i - 1][0], dp[i - 1][1]);

		}

		for (int i = 0; i < 3; i++) {
			if (i != first)	// ù��°�� �������� ��ġ�� ���� ��쿡 ��� ����
				res = dp[N][i] < res ? dp[N][i] : res;
			
		}
	}
	cout << res << endl;
}