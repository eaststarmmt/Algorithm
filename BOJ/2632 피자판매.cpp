#include <bits/stdc++.h>
using namespace std;

int target, M, N, res;
int a[1004], b[1004], psum_a[2004], psum_b[2004];
map<int, int> acnt, bcnt;	// <key, value>가 <합, 개수>

void setInterval(int n, int psum[], map<int, int>& cnt) {		// 구간별로 합 구해서 저장
	for (int interval = 1; interval <= n; interval++) {		// 간격 1부터 n까지
		for (int start = interval; start <= interval + n - 1; start++) {
			int sum = psum[start] - psum[start - interval];
			cnt[sum]++;		// 해당 구간의 덧셈 값을 키로 잡고 카운팅.
			if (interval == n) break;	// 이 로직은 n만큼 중복이 되는데 interval이 n일때는 전체를 다 더한 것이므로 한번만 해야 됨
		}	// end of for map에 저장
	}	// end of for 구간
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> target >> M >> N;

	for (int i = 1; i <= M; i++) {	// A 피자 입력 받으면서 누적합 저장
		cin >> a[i];
		psum_a[i] = psum_a[i - 1] + a[i];	// 누적합 저장. 인덱스를 1부터 사용했기 때문에 0번째에 대한 고민 안해도 됨
	}	// end of for

	for (int i = M + 1; i <= M * 2; i++) {
		psum_a[i] = psum_a[i - 1] + a[i - M];	// 피자가 회전형이라서 연속되는 부분 저장하기 위해 두바퀴 누적합을 저장
	}	// end of for 

	for (int i = 1; i <= N; i++) {	// B 피자 입력 받으면서 누적합 저장
		cin >> b[i];
		psum_b[i] = psum_b[i - 1] + b[i];	// 누적합 저장. 인덱스를 1부터 사용했기 때문에 0번째에 대한 고민 안해도 됨
	}	// end of for

	for (int i = N + 1; i <= N * 2; i++) {
		psum_b[i] = psum_b[i - 1] + b[i - N];	// 피자가 회전형이라서 연속되는 부분 저장하기 위해 두바퀴 누적합을 저장
	}	// end of for 

	setInterval(M, psum_a, acnt);
	setInterval(N, psum_b, bcnt);

	for (int i = 1; i < target; i++) {
		res += acnt[i] * bcnt[target - i];
	}

	res += acnt[target] + bcnt[target];

	cout << res << "\n";

	return 0;
}