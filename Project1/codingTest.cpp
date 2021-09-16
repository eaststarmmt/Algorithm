#include<cstdio>
using namespace std;

void moo(int N) {
	int S = 3;		// 현재 S 수열의 값
	int mid = 4;	// 중간에 moooo 이부분
	
	while(N > S) {	// 수열의 몇번째 열인지 확인하는 과정
		S = S * 2 + mid;
		mid++;
	}
	mid--;			// mid가 불필요하게 한번 늘어나서 다시 돌려줌

	while (true) {		// moooooo 이부분만 남기고 다 날리는게 목적
		int preS = (S - mid) / 2;	// 이전 수열의 길이

		if (N <= preS) {	// 앞부분일때 앞부분만 남기고 다시 루프
			S = preS;
			mid--;
		}
		else if (N > mid + preS) {	// 뒷부분일때 N값을 앞에 두 부분 날림으로 앞부분인것처럼 바꾸고 다시 무한 루프
			N -= mid + preS;
			mid--;
			S = preS;
		}
		else {		// 중간부분이면 앞부분 날려주고 루프 탈출
			N -= preS;
			break;
		}
		
	}
	if (N == 1) printf("m\n");	// mooooo 이부분만 남은 상황이므로 첫번째 아니면 무조건 o
	else printf("o\n");
}

int main() {
	int N;
	scanf("%d", &N);

	moo(N);
}