#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<pair<int, int>> jam;	
	
	for (int i = 0; i < n; i++) {
		int m, v;
		scanf("%d %d", &m, &v);
		jam.push_back({ m , v });
	}

	vector<int> bag;
	
	for (int i = 0; i < k; i++) {
		int c;
		scanf("%d", &c);
		bag.push_back(c);
	}

	sort(jam.begin(), jam.end());	// 보석 무게로 오름차순 정렬
	sort(bag.begin(), bag.end());	// 가방 무게 오름차순으로 정렬
	long long sum = 0;
	
	priority_queue<int> value;
	int idx = 0;	// 우선순위 큐에 넣은 인덱스 알기 위해
	// 가방이 오름차순이므로 이전에 넣었던 보석들은 다시 해보지 않아도 들어감
	// 다음 인덱스부터 해서 이미 넣은 보석이 없는 상태로 우선순위 큐가 구성될 수 있음
	// 작은 가방에 넣을 수 있는 가장 비싼 보석을 하나하나 채워가는 방법
	for (int i = 0; i < k; i++) {
		while (idx < n && jam[idx].first <= bag[i]) {	// for하고 if 쓰면 시간초과 나서 while로 한번에 해야됨
			value.push(jam[idx].second);
			idx++;
		}
		if (!value.empty()) {		// value 비어있으면 double free 발생하므로
			sum += value.top();
			value.pop();
		}
	}
	printf("%lld", sum);

}