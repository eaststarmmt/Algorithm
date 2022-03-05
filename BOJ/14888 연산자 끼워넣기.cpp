#include<stdio.h>
#include<vector>
#include<algorithm>
#define MIN -1e9
#define MAX 1e9
using namespace std;

vector<int> seq;
int oper[4];
int n;
int maxResult = MIN, minResult = MAX;

void recursive(int idx, int curResult) {
	if (idx == n - 1) {
		maxResult = max(maxResult, curResult);
		minResult = min(minResult, curResult);
		return;
	}	// 기저조건

	if (oper[0] > 0) {			// 기본적인 순열 알고리즘 개념. 중복 제거하기 위해 사용한 후 1을 줄이고 다음 재귀를 위해 다시 1 늘리는 방식
		oper[0]--;
		recursive(idx + 1, curResult + seq[idx + 1]);
		oper[0]++;
	}

	if (oper[1] > 0) {
		oper[1]--;
		recursive(idx + 1, curResult - seq[idx + 1]);
		oper[1]++;
	}

	if (oper[2] > 0) {
		oper[2]--;
		recursive(idx + 1, curResult * seq[idx + 1]);
		oper[2]++;
	}

	if (oper[3] > 0) {
		oper[3]--;
		recursive(idx + 1, curResult / seq[idx + 1]);
		oper[3]++;
	}
}

int main() {
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		seq.push_back(x);
	}
	
	
	for (int i = 0; i < 4; i++) {
		scanf("%d", &oper[i]);
	}

	recursive(0, seq[0]);
	printf("%d\n%d\n", maxResult, minResult);
}