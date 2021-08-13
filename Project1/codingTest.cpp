#include<stdio.h>
#include<vector>
#include<queue>
#define MAX 9876543210	// ���Ҿ��� ������ ������ �ʿ� ������. �׷��� �̰ɷ� long long ��ߵǴ°� �˾���
using namespace std;

// ���Ҿ����� �õ��ߴٰ� ����.
// ť�� ����ߴµ� �̰� brute force�� �ǵ��� �´�����...
int main() {
	
	int N;
	scanf("%d", &N);
	vector<long long> decrease;
	queue<long long> queue;
	
	for (int i = 0; i <= 9; i++) {	// 0 ~ 9 ���� ���ڸ� ���� �� �־�д�.
		decrease.push_back(i);
		queue.push(i);
	}

	while (queue.size() > 0) {		// ť�� �� ������ ��� �ݺ�
		if (decrease.size() == N) break;	// ���ϴ� ������ ���� �������� �ߴ�
		long long x = queue.front();		// queue�� ���� ������������ ������. 
		queue.pop();
		for (int i = 0; i < x % 10; i++) {	// x�� 1���ڸ������� ũ�� ���� ���ڸ� �ڿ� �ٿ���.
			long long y = x * 10 + i;		// x�� ���� 10�� ���ؼ� �ڸ����� �÷��ְ� ������ ������ ���� ���� �ڿ� �ٿ���
			decrease.push_back(y);
			queue.push(y);				// �� ���� �ִ� ������ �پ��� ���ڰ� �ϼ� �� ���� 1�� �ڸ��� �� ���� ���ڸ� �ٿ��ִ� �۾��� �ݺ��ϱ� ����
		}
	}
	
	if (N > decrease.size())	// ���ڸ��� ���ڶ��� �������� �ϸ� �ȵ�
		printf("%d\n", -1);
	else
		printf("%lld\n", decrease[N - 1]);
}