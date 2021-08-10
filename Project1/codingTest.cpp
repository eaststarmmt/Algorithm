#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 1000

int main() {
	int n;
	scanf("%d", &n);

	int dp[MAX];
	int input[MAX];

	int result = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}
	
	for (int i = 0; i < n; i++) {	// ���� ������ �ִ� ��
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (input[i] > input[j]) {
				dp[i] = max(dp[i], dp[j] + 1);	// j��° �� ���ٴ� ũ�� ������ ������ 1 �� ŭ
			}
		}
		result = max(result, dp[i]);	// i��° �׺��� ������ �� ū�� ������ �װ� �̾ƾ� ��
	}									// �ڿ��� ���� ���� ����̹Ƿ� i ���� �ٶ� �ִ븸 �� �� ��ü�� �ִ밡 ���� ����
	
	printf("%d\n", result);
}