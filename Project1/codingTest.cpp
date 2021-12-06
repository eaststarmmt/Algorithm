#include<iostream>
#include<map>
#include<string>
#define endl "\n"
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; test++) {
		int N;
		cin >> N;
		map<string, int> cnt;
		for (int i = 0; i < N; i++) {
			string item, classification;
			cin >> item >> classification;
			cnt[classification]++;	// 분류 별로 숫자만 카운팅
		}

		int ans = 1;
		for (auto i : cnt) {
			ans *= i.second + 1;	// 분류별 모든 옷 경우 다 + 1 해서 곱함. 옷의 수 + 안입는 경우
		}
		cout << ans - 1 << endl;	// 알몸인 경우 빼줘야 하므로 - 1
	}
}