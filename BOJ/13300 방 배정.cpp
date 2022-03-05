#include<cstdio>
using namespace std;



int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	int m[7] = { 0 };
	int w[7] = { 0 };

	for (int i = 0; i < N; i++) {
		int S, Y;
		scanf("%d %d", &S, &Y);
		if (S == 0) w[Y]++;
		else m[Y]++;
	}

	int result = 0;

	for (int i = 1; i <= 6; i++) {
		result += (m[i] / K) + (w[i] / K);
		if (m[i] % K != 0) result++;
		if (w[i] % K != 0) result++;
	}
	printf("%d\n", result);
}
/*
16 2
1 1
0 1
1 1
0 2
1 2
0 2
0 3
1 3
1 4
1 3
1 3
0 6
1 5
0 5
1 5
1 6
*/