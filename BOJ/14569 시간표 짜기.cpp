#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	
	vector<long long> sub;		// 50 넘는 숫자 있으므로 64bit 까지 사용되는 longlong 사용

	for (int i = 0; i < N; i++) {
		int K;
		scanf("%d", &K);
		sub.push_back(0);		// 벡터에 넣기 위해 일단 0 push
		for (int j = 0; j < K; j++) {
			int x;
			scanf("%d", &x);
			sub[i] |= ((long long)1 << x - 1);	// 1을 x -1 만큼 쉬프트 한 값을 or 연산해서 그 자리를 1로 바꿈. long long 1이 int라서 터짐
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
			long long cmp = ~student & sub[j];	// 학생의 비어있는 시간과 과목의 해당 시간이 맞아야 하므로 ~ 연산 후에 &연산을 하여 0이 되면 해당 과목 수강 가능
			if (cmp == 0) cnt++;
		}
		printf("%d\n", cnt);
	}

}