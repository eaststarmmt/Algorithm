#include<cstdio>
using namespace std;

int main() {
	int k;
	scanf("%d", &k);
	int result1 = 1, result2 = 1;
	int len[6];
	for (int i = 0; i < 6; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		len[i] = y;

	}

	int sPoint = 0;
	while (true) {
		if (len[sPoint] > len[sPoint + 2] && len[sPoint + 1] < len[sPoint + 5]) break;
		sPoint++;
	}

	result1 = len[sPoint % 6] * len[(sPoint + 5) % 6];
	result2 = len[(sPoint + 2) % 6] * len[(sPoint + 3) % 6];

	printf("%d\n", (result1 + result2) * k);
}