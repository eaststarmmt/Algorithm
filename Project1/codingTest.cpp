#include<cstdio>
using namespace std;

int main() {
	int k;
	scanf("%d", &k);
	int map[6] = { 0 };
	int max1 = -1, max2 = -1;
	for (int i = 0; i < 6; i++) {
		int x;
		scanf("%d %d", &x, &map[i]);
		if (i % 2 == 0) max1 = map[i] > max1 ? map[i] : max1;	// 짝수일때 가장 긴 길이
		else max2 = map[i] > max2 ? map[i] : max2;				// 홀수일때 가장 긴 길이
	}

	int w, h;

	for (int i = 0; i < 6; i++) {

		if (i % 2 == 0) {								// 짝수일때 max1이었으므로 비교는 max2랑 해야됨
			if (max2 == map[(i + 5) % 6] + map[(i + 1) % 6])
				w = map[i];
		}
		else {
			if (max1 == map[(i + 5) % 6] + map[(i + 1) % 6])
				h = map[i];
		}

	}

	printf("%d\n", k * (max1 * max2 - w * h));
}