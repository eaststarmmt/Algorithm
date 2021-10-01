#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	vector<int> sensor;
	for (int i = 0; i < N; i++) {	// 센서 위치 입력받기
		int x;
		scanf("%d", &x);
		sensor.push_back(x);
	}

	sort(sensor.begin(), sensor.end());	// 오름차순 정렬
	vector<int> dis;
	for (int i = 1; i < N; i++) {
		dis.push_back(sensor[i] - sensor[i - 1]);	// 센서간 거리 입력
	}
	sort(dis.begin(), dis.end(), greater<int>());	// 내림차순 정렬
	int ans = 0;
	for (int i = K - 1; i < dis.size(); i++) {	// K개 만큼 집종국으로 대체 가능 하므로 큰 순서대로 K개 제외하고 더함
		ans += dis[i];
	}
	printf("%d\n", ans);
}