#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int num[1001];
long long result;

void divideCon(int start, int end, int maxValue) {
	if (start == end) return;					// ���۰� �� ���� ������ ī���� �ȵǹǷ� ����
	int nowMax = *max_element(num + start, num + end);	// �ִ밪 ã��. end�� �迭 ������
	int maxIndex = find(num + start, num + end, nowMax) - num;	// �ִ밪 �ε��� ã��

	if (start <= maxIndex - 1) divideCon(start, maxIndex, nowMax);	// �ִ밪 ��ġ�� ���� �� ������. maxIndex���� ������ end -1 ��ŭ�� Ž����
	if (maxIndex + 1 < end) divideCon(maxIndex + 1, end, nowMax);	// ������ �� ������.

	result += maxValue - nowMax;	// ������ �ִ밪 - ���� �ִ밪 ��ŭ ���ؾ� ���ڰ� ������
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
		maxValue = x > maxValue ? x : maxValue;	// �ִ밪 ���
	}

	divideCon(0, N, maxValue);
	printf("%lld\n", result);
}