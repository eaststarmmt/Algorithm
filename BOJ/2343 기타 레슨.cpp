#include<cstdio>
#include<vector>
#include<algorithm>
#define INF 1e9
using namespace std;

int binarySearch(vector<int> lecture, long long start, long long end, long long target) {
	long long minBlue = INF;			// �ּҰ� ���ϱ� ������ ū ������ �ʱ�ȭ

	while (start <= end) {
		long long mid = (start + end) / 2;			// ��緹���� ũ�� ã�� ����
		long long sum = 0;
		long long total = 0;
		long long cnt = 1;

		for (int i = 0; i < lecture.size(); i++) {
			if (sum + lecture[i] <= mid) sum += lecture[i];	// ũ�� ���� �ȳ����� ���ϰ� ������ ���� ����鼭 ī����
			else {
				total = sum > total ? sum : total;
				sum = lecture[i];
				cnt++;
			}
		}

		total = sum > total ? sum : total;

		if (cnt > target) {			// cnt�� �� ũ�� �߰� �ɰ����� ������ start �� Ű��
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
		sum += x;				// ���� �� �� ���ؼ� end�� ����
	}

	printf("%lld\n", binarySearch(lecture, 0, sum, M));
}