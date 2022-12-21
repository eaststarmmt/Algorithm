#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int N;
pair<int, int> res(-INF, INF);
int oper[4], a[14];

void comb(int cnt, int cur, int plus, int minus, int mul, int div) {
	if (cnt == N - 1) {
		res.first = max(res.first, cur);
		res.second = min(res.second, cur);
	}

	if (plus) {
		comb(cnt + 1, cur + a[cnt + 1], plus - 1, minus, mul, div);
	}

	if (minus) {
		comb(cnt + 1, cur - a[cnt + 1], plus, minus - 1, mul, div);
	}

	if (mul) {
		comb(cnt + 1, cur * a[cnt + 1], plus, minus, mul - 1, div);
	}

	if (div) {
		comb(cnt + 1, cur / a[cnt + 1], plus, minus, mul, div - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}

	comb(0, a[0], oper[0], oper[1], oper[2], oper[3]);

	cout << res.first << "\n" << res.second << "\n";

	return 0;
}