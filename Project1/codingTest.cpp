#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n , k, result;		// 재귀로 돌리기 위해 전역변수 선언
vector<int> vec;		// k의 원소들

void recursive(int x) {
	if (n < x) return;	// x 가 0보다 크면 조건에 안맞으므로 탈출
	result = result < x ? x : result;	// result보다 확인 하려는 x값이 크면 x값을 넣어줌. 결국 n이하의 숫자 중 최대값이 남는다
	for (int i = 0; i < k; i++) {
		recursive(10 * x + vec[i]);		// x에 10을 곱해서 한자리씩 올리고 k의 원소를 하나씩 붙여서 확인하는 방식
	}

}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end(), greater<int>());	// 내림차순으로 정렬
	recursive(0);
	printf("%d\n", result);
}