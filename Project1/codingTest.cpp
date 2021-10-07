#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int num[1001];
long long result;

void divideCon(int start, int end, int maxValue) {
	if (start == end) return;					// 시작과 끝 값이 같으면 카운팅 안되므로 리턴
	int nowMax = *max_element(num + start, num + end);	// 최대값 찾기. end는 배열 사이즈
	int maxIndex = find(num + start, num + end, nowMax) - num;	// 최대값 인덱스 찾기

	if (start <= maxIndex - 1) divideCon(start, maxIndex, nowMax);	// 최대값 위치의 왼쪽 값 보내기. maxIndex까지 보내도 end -1 만큼만 탐색됨
	if (maxIndex + 1 < end) divideCon(maxIndex + 1, end, nowMax);	// 오른쪽 값 보내기.

	result += maxValue - nowMax;	// 기존의 최대값 - 현재 최대값 만큼 더해야 숫자가 맞춰짐
}

int main() {
	int N;
	scanf("%d", &N);
	
	int maxValue = -1;
	int idx;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		num[i] = x;
		maxValue = x > maxValue ? x : maxValue;	// 최대값 기록
	}

	divideCon(0, N, maxValue);
	printf("%lld\n", result);
}