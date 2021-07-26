#include<stdio.h>
using namespace std;

int main() {
	while (1) {
		int l, p, v;
		scanf("%d %d %d", &l, &p, &v);
		if (l == 0 && p == 0 && v == 0) break;		// 모두 0 들어오면 종료
		int sum = 0;
		int cnt = 1;
		while (v > 0) {			
			if (v > p) {	// v 가 충분히 크면 v는 p만큼 줄이면서 l 값을 계속 더해줌
				v -= p;
				sum += l;
			}
			else {			// v 가 많이 작아진 상황
				if(v > l) {	// l보다 크면 l만큼 더함
					sum += l;
					v = 0;
				}
				else {		// l보다 작으면 v를 더함
					sum += v;
					v = 0;
				}
				
			}
		}
		printf("Case %d: %d\n", cnt, sum);
		cnt++;
	}
}