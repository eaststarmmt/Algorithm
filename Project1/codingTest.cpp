#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int binarySearch(vector<int> input, int start, int end, int target) {
	
	int maxValue = 0;

	while (start <= end) {
		int mid = (start + end) / 2;		// 상한값을 확인할 변수
		int sum = 0;
		for (int i = 0; i < input.size(); i++) {
			if (mid < input[i]) sum += mid;		// 상한값 보다 크면 상한값 넣기
			else sum += input[i];			// 작으면 그냥 넣기
		}

		if (sum <= target) {				// 합이 예산 이하이면 start 늘려서 더 큰 값 넣을수 있는지 찾기
			start = mid + 1;
			maxValue = mid > maxValue ? mid : maxValue;
		}
		else end = mid - 1;				// 예산보다 크면 end값 줄여서 조건에 맞춰보기
	}
	return maxValue;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<int> input;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		input.push_back(x);
		sum += x;				// 예산과 비교하기 위해 미리 합을 구해둠
	}
	int M;				
	scanf("%d", &M);
	sort(input.begin(), input.end());
	
	if (sum <= M) {		// 합이 예산 이하이면 최대값 출력
		printf("%d\n", input[input.size() - 1]);
		return 0;
	}

	printf("%d\n", binarySearch(input, 0, input[input.size() - 1], M));
}