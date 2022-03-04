#include<cstdio>
#include<vector>
#include<algorithm>
#define INF 1e9
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {	// 마감 시간 기준으로 내림차순
	return a.second > b.second;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<pair<int, int>> work;

	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		work.push_back({ x, y });
	}

	sort(work.begin(), work.end(), cmp);

	int early = INF;	// 아니 ㅅㅂ 하루가 24시까지 있지 무슨 100만 시간까지 허용해주면 왜 문제에 하루라고 적었는지 하루가 뭔지 개념 자체가 없는 인간이 만든 문제
						// 몇시부터 시작해야 되는지 결과값 뽑을 변수
	for (int i = 0; i < work.size(); i++) {
		if (early > work[i].second) early = work[i].second;		// early 값이 마감시간보다 크다면 의미 없는 상황. early를 마감시간으로 땡겨준다
		early -= work[i].first;					// early값 걸리는 시간만큼 앞으로 땡김
	}
	if (early < 0) printf("%d\n", -1);			// 0보다 작으면 주어진 시간에 불가능 하거나 일정이 겹치는 상황
	else printf("%d\n", early);					// 그 외의 경우 정상출력

}