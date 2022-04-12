#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct Line {
	int x, y;
};

bool cmp(Line a, Line b) {	// 왼쪽 점 기준으로 오름차순
	return a.x < b.x;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<Line> dots;
	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		dots.push_back({ x, y });
	}	// end of input

	sort(dots.begin(), dots.end(), cmp);

	int ans = 0;
	int left = dots[0].x;		// 현재 확인하고 있는 선의 왼쪽 좌표
	int right = dots[0].y;		// 현재 확인하고 있는 선의 오른쪽 좌표

	for (int i = 1; i < N; i++) {
		if (dots[i].x <= right) {	// 지금 보고 있는 선 안으로 새로 그린 선이 들어오는 경우
			right = dots[i].y > right ? dots[i].y : right;	// 선의 길이가 최대가 되도록 갱신
		}
		else {		// 새로 그린 선이 포함이 되지 않는 경우
			ans += right - left;	// 선 길이 더해주기
			left = dots[i].x;		// 새로운 선의 왼쪽 좌표 저장
			right = dots[i].y;		// 새로운 선의 오른쪽 좌표 저장
		}
	}	// end of calc without Nth line
	ans += right - left;
	printf("%d\n", ans);
}