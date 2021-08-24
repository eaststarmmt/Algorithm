#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	int T;
	scanf("%d", &T);
	
	for (int test = 1; test <= T; test++) {
		int N;
		scanf("%d", &N);
		vector<int> vec1, vec2;
		vec1.push_back(1);				
		printf("#%d\n", test);
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < i; j++) {
				if (j == 0) {				// 첫 인덱스는 무조건 0이 들어감
					printf("%d ", 1);
					vec2.push_back(1);		// 다음줄에서 사용하기 위해 저장
				}
				else if (j == i - 1) {		// 마지막 인덱스는 무조건 0이 들어감
					printf("%d ", 1);
					vec2.push_back(1);
				}
				else {						// 중간에 들어오는 값들은 이전 줄의 (바로 전 인덱스 값 + 현재 인덱스값)
					printf("%d ", vec1[j - 1] + vec1[j]);
					vec2.push_back(vec1[j - 1] + vec1[j]);
				}
			}
			vec1.assign(vec2.begin(), vec2.end());	// 이번줄에서 나온 값을 vec2에 복사
			vec2.clear();							// 다음 줄에서 값을 받기 위해 vec2를 비움
			printf("\n");
		}
	}
}