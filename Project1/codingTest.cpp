#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> tower;	
	
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		tower.push_back(x);
	}
	stack<pair<int, int>> result;	// 값, 인덱스 형태
	result.push({ tower[0], 1 });	// 첫번째 값은 무조건 푸쉬
	printf("%d ", 0);				// 처음에는 무조건 0 출력
	for (int i = 1; i < n; i++) {
		bool fail = false;			// 모든 스택에 있는 값보다 큰 경우 체크하기 위한 플래그
		while (!result.empty()) {	// 스택이 빌때까지 계속 비교
			if (tower[i] > result.top().first) {	// top의 값 보다 더 큰 경우
				result.pop();						// 다음 값 비교를 위해 스택에서 빼냄
				fail = true;
			}
			else {
				printf("%d ", result.top().second);		// top이 더 크면 top에 있는 타워 인덱스 출력
				result.push({ tower[i], i + 1 });		// 현재 tower값 스택에 올리기
				fail = false;
				break;
			}
		}
		if (fail) {										// 스택안에 모든 값보다 더 큰 경우
			printf("%d ", 0);							// 0 출력하고 스택에 넣기
			result.push({ tower[i], i + 1 });
		}
	}
}