#include<cstdio>
using namespace std;

int main() {
	long long k;
	scanf("%lld", &k);
	int flag = 0;	// 짝수에서 넘어왔으면 색 숫자 바뀌는거 고려해서 플래그 변수 준비
	while (1) {
		if (k == 1) {
			printf("%d", (0 + flag) % 2);	
			break;
		}
		else if (k == 2) {			
			printf("%d", (1 + flag) % 2);
			break;
		}
		if (k % 2 == 1) k = k / 2 + 1;	// 홀수의 경우에는 /2 +1 한 인덱스와 같은 값을 가짐
		else {							// 짝수는 /2 한 인덱스와 반대 값을 가짐
			k = k / 2;
			flag = (flag + 1) % 2;
		}
	}
}