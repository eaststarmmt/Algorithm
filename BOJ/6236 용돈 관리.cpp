#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
using namespace std;

int N, M;
vector<int> pocket;
int sum;
int binarySearch(int start, int end) {
	int result = sum;	// 출력할 결과값 저장할 변수
	while (start <= end) {
		int mid = (start + end) / 2;	// 얘가 문제에서 K 즉 인출하는 금액
		int haveMoney = mid;
		int cnt = 1;			// 인출 카운팅
		for (int i = 0; i < N; i++) {
			if (haveMoney < pocket[i]) {	// 가진돈이 더 작으면 다시 mid 만큼 맞춰주고 카운팅
				cnt++;
				haveMoney = mid;
			}
			haveMoney -= pocket[i];		// 가진돈에서 필요 금액만큼 빼줌
			
		}
		if (cnt > M) start = mid + 1;	//	cnt가 M보다 크면 정답에 영향을 안줌
		else {							// 현우가 M 보다 적게 인출하더라도 
			end = mid - 1;				// M을 맞추려고 다시 인출하는 변태같은 성향이 있다고 밝힘
			result = mid < result ? mid : result;	// 즉 M보다 작은 경우도 정답이 될 수 있기에 result 값 갱신에 영향을 줌
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int maxValue = 0;				// 가장 비싼 값을 최소값으로 보내야 됨
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		pocket.push_back(x);
		sum += x;					// 합을 최대값으로 보내야 됨
		maxValue = x > maxValue ? x : maxValue;
	}

	cout << binarySearch(maxValue, sum) << endl;
}