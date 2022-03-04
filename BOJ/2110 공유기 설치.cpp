#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearch(vector<int> input, int start, int end, int target) {
	int maxDis = 0;		// 가장 큰 최소 거리
	while (start <= end) {
		int mid = (start + end) / 2;	// 최소거리를 중간 값으로 탐색. 시작점과 끝 점의 중간값을 탐색하는 방식 이용
		int last = 0;					// 최근에 공유기가 설치된 곳의 인덱스
		int cnt = 1;					// 설치된 공유기 개수
		for (int i = 1; i < input.size(); i++) {
			int dis = input[i] - input[last];	// 마지막 설치된 곳과 현재 위치의 거리
			if (dis >= mid) {			// mid보다 큰 경우만 설치
				cnt++;
				last = i;
			}
			
		}
		if (cnt >= target) {		// target 의 개수 이상 설치 된 경우
			start = mid + 1;		// start 값을 늘려서 mid 값을 키움
			maxDis = mid > maxDis ? mid : maxDis;	// target 만큼 설치 가능하단 뜻이기 때문에 최대최소거리 갱신
		}
		else end = mid - 1;			// end 값을 줄여서 mid 값을 줄임		
	}
	return maxDis;
}

int main() {

	int N, C;
	scanf("%d %d", &N, &C);
	vector<int> input;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		input.push_back(x);
	}
	sort(input.begin(), input.end());
	printf("%d", binarySearch(input, 0, input[input.size() - 1], C));	// 시작점은 input과 상관없이 무조건 0으로 해야 끝점과의 정확한 중간값이 나옴

}