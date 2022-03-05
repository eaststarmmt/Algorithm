#include<cstdio>
#include<cmath>
using namespace std;

int main() {

	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {

		double sum = 0;
		double min = 9999999;
		double max = -1;
		for (int i = 0; i < 10; i++) {
			int x;
			scanf("%d", &x);
			sum += x;					// 입력하면서 다 더함
			max = x > max ? x : max;	// 최대값 따로 분류
			min = x < min ? x : min;	// 최소값 따로 분류
		}
		sum = sum - max - min;			// 합에서 최대 최소 빼줌
		printf("#%d %d\n", test, (int)round(sum / 8));	// 반올림 후 출력
	}

}