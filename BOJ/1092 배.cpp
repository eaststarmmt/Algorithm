#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int N;
	scanf("%d", &N);
	vector<int> crane;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		crane.push_back(x);
	}	// end of for cranes input
	int m;
	scanf("%d", &m);
	vector<int> box;
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		box.push_back(x);
	}	// end of for boxes input

	sort(crane.begin(), crane.end(), cmp);	// 박스, 크레인 내림차순 정렬
	sort(box.begin(), box.end(), cmp);
	if (crane[0] < box[0]) {	// 박스가 크레인 허용 무게보다 크면 종료
		printf("-1\n");
		return 0;
	}
	int time = 0;
	while (m > 0) {	
		for (int i = 0; i < crane.size(); i++) {
			for (int j = 0; j < box.size(); j++) {
				if (crane[i] >= box[j]) {	// 박스 옮길 수 있으면 다음 크레인으로
					box.erase(box.begin() + j);		// bool 배열로 표시하고 continue 하는 것보다 지우는게 더 빠름
					m--;	// 남은 박스 수 카운팅
					break;
				}
			}	// end of for box
		}	// end of for crane 
		time++;
	}	// end of while
	printf("%d\n", time);
}