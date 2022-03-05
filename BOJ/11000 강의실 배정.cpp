#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> time;	// 시작시간 끝 시간 저장할 벡터
	priority_queue<int, vector<int>, greater<int>> endTime;	// 끝 시간만 저장할 우선순위 큐
														// 빨리 끝나는 시간 순서로 정렬하기 위해 min heap 으로 선언
	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		time.push_back({ x, y });
	}
	
	sort(time.begin(), time.end());		// 시작시간 기준으로 오름차순 정렬
	endTime.push(time[0].second);		// 가장 빨리 시작한 강의의 끝나는 시간 push

	for (int i = 1; i < time.size(); i++) {
		if (endTime.top() <= time[i].first) endTime.pop();	// 현재 저장된 가장 빨리 끝나는 시간보다 시작시간이 더 느리거나 같으면 
															// 저장된 강의 pop. 어차피 뒤에서 push해서 개수는 같음
		endTime.push(time[i].second);	// 강의 끝나는 시간 push. 끝나는 시간이 가장 빠른 강의가 top에 있어서 가능한 강의 개수를 유지해줌
	}

	printf("%d\n", endTime.size());	// 우선순위 큐에는 강의시간이 겹치는 애들이 pop되지 못한채로 남아있음. 즉 강의실 개수가 됨
}