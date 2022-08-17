#include <iostream>
#include <string>
#include <algorithm>
#define INF 1e9
using namespace std;

int N;
int coin[24];
int res = INF;
void comb(int start = 0) {
	if (start == N) {
		int sum = 0;
		for (int i = 1; i <= (1 << (N - 1)); i <<= 1) {	// 001 010 100 한줄씩 확인
			int cnt = 0;
			for (int j = 0; j < N; j++) {	// i 번째 자리를 모든 숫자로 확인. 즉 세로줄 확인
				if (coin[j] & i) {
					cnt++;
				}
			}
			sum += min(cnt, N - cnt);	// 세로줄은 뒤집기 안했으므로 뒤집었을때랑 뒤집지 않았을때 중 최소값 더하기
		}	// end of for i
		res = min(res, sum);
		return;
	}

	coin[start] = ~coin[start];	// 동전 가로줄 뒤집기
	comb(start + 1);
	coin[start] = ~coin[start];	// 원상복구
	comb(start + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0, bit = 1; j < s.size(); j++, bit <<= 1) {
			if (s[j] == 'T') {
				coin[i] |= bit;
			}
		}	// end of for j
	}	// end of for i

	comb();
	cout << res << "\n";
	return 0;
}