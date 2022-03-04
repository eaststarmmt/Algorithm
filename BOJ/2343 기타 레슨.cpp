#include<cstdio>
#include<vector>
#include<algorithm>
#define INF 1e9
using namespace std;

int binarySearch(vector<int> lecture, long long start, long long end, long long target) {
	long long minBlue = INF;			// 최소값 구하기 때문에 큰 값으로 초기화

	while (start <= end) {
		long long mid = (start + end) / 2;			// 블루레이의 크기 찾는 변수
		long long sum = 0;
		long long total = 0;
		long long cnt = 1;

		for (int i = 0; i < lecture.size(); i++) {
			if (sum + lecture[i] <= mid) sum += lecture[i];	// 크기 기준 안넘으면 더하고 넘으면 새로 만들면서 카운팅
			else {
				total = sum > total ? sum : total;
				sum = lecture[i];
				cnt++;
			}
		}

		total = sum > total ? sum : total;

		if (cnt > target) {			// cnt가 더 크면 잘게 쪼개졌기 때문에 start 값 키움
			start = mid + 1;
		}
		else {
			end = mid - 1;
			minBlue = total < minBlue ? total : minBlue;
		}
	}
	return minBlue;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	long long sum = 0;
	vector<int> lecture;
	for (int i = 0; i < N; i++) {
		long long x;
		scanf("%d", &x);
		lecture.push_back(x);
		sum += x;				// 강의 총 합 구해서 end값 결정
	}

	printf("%lld\n", binarySearch(lecture, 0, sum, M));
}