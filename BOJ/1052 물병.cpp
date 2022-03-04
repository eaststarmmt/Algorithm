#include<cstdio>
using namespace std;

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	
	int ans = 0;
	int cnt = 1e9;		// while 돌리기 위해 큰 수 집어넣어서 일단 한번 돌림

	// 물병이 2의 배수로 물이 들어 있으므로 2진수로 변형시 1이 되는 곳에 물이 들어 있음
	// ex 26 -> 11010	3통에 들어 있음
	while (cnt > K) {	// cnt가 K 보다 큰 경우만 돌리기
		int ing = N;	// N값을 카운팅 하는 과정에서 바뀌지 않게 복사
		cnt = 0;
		// 1이 몇개 있는지 세기
		do {					// 혹시 처음에 안맞는데 들어갈까봐 do while 사용함
			ing = ing & ing - 1;	// N 과 N - 1을 N이 0이 될때까지 반복하면 횟수 만큼 1이 들어있음
			cnt++;
		} while (ing > 0);
		
		if (cnt <= K) break;	// K개보다 작거나 같으면 종료
								// N & -N 을 하면 가장 적은양이 들어있는 물의 위치를 알 수 있음. 2의 보수 특성임
		ans += N & -N;			// ex) 26 -> 11010  -26 -> 00110
		N += N & -N;			// 가장 작은 양이 들어있는 물병에 물 넣고 다시 진행
	}
	printf("%d\n", ans);
}