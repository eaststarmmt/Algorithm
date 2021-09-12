#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<int> card;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		card.push_back(x);
	}
	sort(card.begin(), card.end());		// 입력받은 카드 오름차순 정렬
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int x;
		scanf("%d", &x);
		if (binary_search(card.begin(), card.end(), x)) {	// 이분탐색으로 있으면 1 없으면 0 출력
			printf("%d ", 1);
		}
		else {
			printf("%d ", 0);
		}
	}
}