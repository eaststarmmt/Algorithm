#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> dis;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int x;
		scanf("%d", &x);
		dis.push_back(x);
	}
	vector<int> fuel;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		fuel.push_back(x);
	}
	int minFuel = fuel[0];	// 기름 최솟값 저장
	long result = (long)fuel[0] * dis[0];	// 두 번째 도시까지 가는데 필요한 기름값
	for (int i = 1; i < n - 1; i++) {
		minFuel = min(minFuel, fuel[i]);	// 현재까지 기름값 중 최소 기름값 찾기
		result += (long)minFuel * dis[i];	// 최소 기름값과 거리의 곱을 더해줘서 현재까지 오는데 드는 최소 비용 계산
	}
	printf("%lld\n", result);
}