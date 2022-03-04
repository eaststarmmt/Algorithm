#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {	// 끝나는 시간이 빠른 순으로 정렬
	if (a.second == b.second) return a.first < b.first;	// 끝나는 시간이 같을 경우 시작시간이 빠른 회의가 먼저 와야 됨
	return a.second < b.second;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<pair<int, int>> input;
	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		input.push_back({ x, y });
	}

	sort(input.begin(), input.end(), cmp);	
	int cnt = 0;
	int nowWork = -1;	// 현재 회의 끝나는 시간
	for (int i = 0; i < input.size(); i++) {
		if (input[i].first >= nowWork) {	// 회의 시작시간이 끝나는 시간보다 크거나 같은경우
			nowWork = input[i].second;	// 회의값 갱신
			cnt++;			// 카운팅
		}
	}
	printf("%d\n", cnt);
}