#include<stdio.h>
#include<set>
using namespace std;

int pizza[1000][1000];

int main() {
	int n, m;
	long long sum = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &pizza[i][j]);
			sum += pizza[i][j];
		}
	}
	set<pair<int, int>> view;	// 중복을 방지하기 위해 set 사용
	int x, y, value;
	for (int i = 0; i < n; i++) {		// front 측정
		x = 0;
		y = 0;
		value = 0;
		for (int j = 0; j < m; j++) {
			if (pizza[i][j] > value) {
				x = i;
				y = j;
				value = pizza[i][j];
			}
		}
		view.insert({ x, y });	// front로 봤을때 보이는 애들 좌표만 따로 저장

		
	}

	for (int j = 0; j < m; j++) {
		x = 0;
		y = 0;
		value = 0;
		for (int i = 0; i < n; i++) {
			if (pizza[i][j] > value) {
				x = i;
				y = j;
				value = pizza[i][j];
			}
		}
		view.insert({ x, y });
	}
	for (auto iter = view.begin(); iter != view.end(); iter++) {	// set은 인덱스가 아닌 주소로 접근
		int i = (*iter).first;
		int j = (*iter).second;
		sum -= pizza[i][j];		// 해당 좌표에 값은 빼줌
	}
	printf("%lld", sum);	// int 범위 넘어가서 long long 으로
}