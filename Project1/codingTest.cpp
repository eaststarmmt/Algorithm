#include<cstdio>
#include<algorithm>
#include<vector>
#define INF 1e9
using namespace std;

int main() {
	int N, H;
	scanf("%d %d", &N, &H);
	vector<int> up, down;
	for (int i = 0; i < N / 2; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		down.push_back(x);		// 밑에서 솟아오르는 애
		up.push_back(y);		// 위에서 내려오는 애
	}
	sort(down.begin(), down.end());	// 이분탐색을 위해 정렬
	sort(up.begin(), up.end());	

	int result = INF, cnt = 0;;


	for (int i = 1; i <= H; i++) {
		int sum, upBreak, downBreak;
		downBreak = lower_bound(down.begin(), down.end(), i) - down.begin();	// 가장먼저 만나는 애 인덱스
		upBreak = upper_bound(up.begin(), up.end(), H - i) - up.begin();		// 전체높이 - 현재높이를 초과하는 첫번째 요소 인덱스
		sum = N - downBreak - upBreak;	// 각각 N / 2 - 밑에서 나오는애 첫 인덱스, N / 2 - 위에서 나오는애 첫 인덱스이기 때문에 N에서 빼줌
		if (result > sum) {	// 새로운 최소값 발견되면 갱신하고 카운팅 초기화
			cnt = 1;
			result = sum;
		}
		else if (result == sum) cnt++;	// 현재 최소값고 같으면 카운팅
	}
	printf("%d %d\n", result, cnt);
}