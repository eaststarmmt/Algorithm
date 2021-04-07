#include<stdio.h>
#include<algorithm>
using namespace std;

int d[1000001];

int main() {
	int n;
	scanf("%d", &n);
	d[2] = 1;
	d[3] = 1;
	for (int i = 4; i <= n; i++) {
		d[i] = d[i - 1] + 1;	// -1을 먼저 처리해야 다른 연산과 최솟값 비교가 쉬움. 이건 무조건 되는 경우기 때문에 얘부터 처리해서 나머지 경우랑 비교하기
		if (i % 2 == 0)			// 2로 나눴을때가 더 작으면 걔로 바꾸기
			d[i] = min(d[i], d[i / 2] + 1);
		
		if (i % 3 == 0) {		// 위랑 마찬가지
			d[i] = min(d[i], d[i / 3] + 1);
		}
	}

	printf("%d\n", d[n]);
}