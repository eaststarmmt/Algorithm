#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int dice[7] = { 0 };
	int dMax = 0;
	long long res = 0;
	for (int i = 1; i <= 6; i++) {
		scanf("%d", &dice[i]);
		res += dice[i];
		dMax = dice[i] > dMax ? dice[i] : dMax;
	}	// end of input

	if (N == 1) {
		printf("%lld\n", res - dMax);
		return 0;
	}

	int select[3] = { 0 };
	select[0] = dice[1] < dice[6] ? dice[1] : dice[6];	// 마주보는 애들 중에 작은값 저장
	select[1] = dice[2] < dice[5] ? dice[2] : dice[5];
	select[2] = dice[3] < dice[4] ? dice[3] : dice[4];
	
	sort(select, select + 3);
	long long side1 = select[0];		// 제일 작은 애가 3번 보여야 됨
	long long side2 = side1 + select[1];
	long long side3 = side2 + select[2];
	res = side3 * 4;	// 3번 보일면으로 4번
	res += side2 * (8 * N - 12);	// 3번 보일 면과 2번 보일면
	res += side1 * ((long long)N * N * 5 - 16 * N + 12);	// 1번만 보일 면
	
	printf("%lld\n", res);

}