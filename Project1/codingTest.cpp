#include<stdio.h>
#include<vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> swit;
	swit.push_back(0);				// 1번째 인덱스부터 확인하기 위해 의미없는 0을 넣어줌
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		swit.push_back(x);
	}
	int student;
	scanf("%d", &student);
	for (int i = 0; i < student; i++) {
		int gender, num;
		scanf("%d %d", &gender, &num);
		switch (gender) {
		case 1:
			for (int i = num; i <= n; i++) {		// 남자인 경우 num 이하 인덱스는 볼 필요 없음
				if (i % num == 0) {					// num의 배수일 경우 숫자 바꿈
					swit[i] = (swit[i] + 1) % 2;
				}
			}
			break;
		case 2:
			swit[num] = (swit[num] + 1) % 2;		// 여자의 경우 num번째 인덱스는 무조건 누름
			for (int i = 1; i <= n; i++) {
				int left = num - i;					// 좌우 인덱스 대칭 이동
				int right = num + i;
				if ((left < 1) || (right > n))		// 인덱스 범위를 넘어가면 break;
					break;

				if (swit[left] == swit[right]) {	// 좌우 같으면 값 바꿔줌
					swit[left] = (swit[left] + 1) % 2;
					swit[right] = swit[left];
				}
				else								// 대칭이 아니면 종료
					break;
				
			}
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", swit[i]);
		if (i % 20 == 0)
			printf("\n");
	}
}