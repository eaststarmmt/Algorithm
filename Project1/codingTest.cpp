#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	
	vector<long long> sub;		// 50 �Ѵ� ���� �����Ƿ� 64bit ���� ���Ǵ� longlong ���

	for (int i = 0; i < N; i++) {
		int K;
		scanf("%d", &K);
		sub.push_back(0);		// ���Ϳ� �ֱ� ���� �ϴ� 0 push
		for (int j = 0; j < K; j++) {
			int x;
			scanf("%d", &x);
			sub[i] |= ((long long)1 << x - 1);	// 1�� x -1 ��ŭ ����Ʈ �� ���� or �����ؼ� �� �ڸ��� 1�� �ٲ�. long long 1�� int�� ����
		}
	}

	int M;
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int P;
		scanf("%d", &P);
		long long student = 0;
		for (int j = 0; j < P; j++) {
			int q;
			scanf("%d", &q);
			student |= ((long long)1 << q - 1);
		}
		
		int cnt = 0;

		for (int j = 0; j < N; j++) {
			long long cmp = ~student & sub[j];	// �л��� ����ִ� �ð��� ������ �ش� �ð��� �¾ƾ� �ϹǷ� ~ ���� �Ŀ� &������ �Ͽ� 0�� �Ǹ� �ش� ���� ���� ����
			if (cmp == 0) cnt++;
		}
		printf("%d\n", cnt);
	}

}