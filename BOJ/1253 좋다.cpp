#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	vector<long long> num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long x;
		cin >> x;
		num.push_back(x);
	}	// 입력값 벡터에 세팅

	sort(num.begin(), num.end());
	int cnt = 0;
	for (int i = 0; i < N; i++) {	// 이분탐색 개념 비슷하게 이용. i번째 값 되는지 찾기
		int start = 0, end = N - 1;
		while (start < end) {		// 같은거 두번 못 더해서 end가 클 때만 사용 가능
			long long sum = num[start] + num[end];
			if (sum == num[i]) {
				if (start != i && end != i) {
					cnt++;
					break;
				}
				else if (start == i)	// start가 같으므로 오른쪽으로 이동
					start++;
				else if (end == i)		// start가 같으므로 왼쪽으로 이동
					end--;
			}
			else if (sum < num[i])	// 정렬 되어 있으므로 작을 경우 왼쪽 포인터를 오른쪽으로 이동
				start++;
			else					// 클 경우 오른쪽 포인터를 왼쪽으로 땡겨서 값 조절
				end--;
		}
	}
	cout << cnt << endl;
}