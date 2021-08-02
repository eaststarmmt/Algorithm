#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> input;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		input.push_back(x);
	}
	sort(input.begin(), input.end());		// 입력받은 값들 오름차순 정렬
	int target = 1;				// 처음에 1이 되는지 확인 해야 되므로
	for (auto x : input) {
		if (target < x)			// 타겟이 x 보다 작으면 타겟은 만들 수 없는 값
			break;
		target += x;		// target + x 가 다음 값 보다 작다면 그 값들은 모두 만들어 짐
	}
	printf("%d", target);
}