#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 501		// 배열은 100개면 충분하지만 A가 500번까지 들어와서 500개 사용. 그냥 pair써서 sort하는게 나을수도 있을거 같음

int main() {

	int n;
	scanf("%d", &n);

	int line[MAX] = { 0 };		// 0 인경우 걸러야 되기 때문에 두개 다 0으로 초기화 
	int dp[MAX] = { 0 };


	int last = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		line[x] = y;			// A의 x번째 전깃줄에서 B의 y번째 전깃줄. 근데 pair 쓰는게 나을듯
		last = max(last, x);	// 중간에 비는게 있어서 배열을 개수로 돌리면 뒤에는 확인을 안함
	}

	int result = 0;

	for (int i = 1; i <= last; i++) {
		if (line[i] == 0) continue;		// 선 없는데 괜히 dp에 1 넣어버리면 LIS 계산하는 과정에서 1씩 더 나옴
		dp[i] = 1;

		for (int j = 1; j < i; j++) {
			if (line[i] > line[j]) {
				dp[i] = max(dp[i], dp[j] + 1);		// j 보다 크다는 말은 j까지의 LIS보다 무조건 1은 더 크다는 소리
			}
		}
		result = max(dp[i], result);		// 지금까지 나온 LIS 값들 중 최대값 가져가기
	}

	printf("%d", n - result);				// 전체 선 개수에서 LIS 빼주면 버려야 되는 선 개수 나옴
}