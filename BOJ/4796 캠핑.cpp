#include<stdio.h>
using namespace std;

int main() {
	int cnt = 1;
	while (1) {
		int l, p, v;
		scanf("%d %d %d", &l, &p, &v);
		if (l == 0 && p == 0 && v == 0) break;		// 모두 0 들어오면 종료
		int sum = v / p * l;						// 총 일수 / 연속 기준 * 사용가능한 날
		int surplus = v % p > l ? l : v % p;		// 나머지가 사용가능한 날보다 크면 l 아니면 나머지 
		sum += surplus;
		printf("Case %d: %d\n", cnt, sum);
		cnt++;
	}
}