#include<cstdio>
#include<algorithm>
using namespace std;

int logs[10001];
// 가운데에 가장 큰 숫자를 넣고 양쪽에 번갈아 가며 순서대로 배치하면 차이가 최소가 됨
// 이걸 반대로 생각하면 오름차순으로 배치한 후에 양 끝에 번갈아가며 배치하면 같은 결과를 얻음
// 결론적으로 오름차순으로 정렬 한 후 하나 건너서 크기를 비교하면 굳이 재배치를 하지 않아도 결과를 얻게됨
int main() {
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &logs[i]);
		}	// end of for logs
		sort(logs, logs + N);	// 오름차순 정렬
		int res = 0;
		for (int i = 2; i < N; i++) {	// 하나 건너 있는것과 비교해서 최소값 뽑기
			int dif = logs[i] - logs[i - 2];
			res = dif > res ? dif : res;
		}	// end of for dif
		
		printf("%d\n", res);
	}	// end of for test
}