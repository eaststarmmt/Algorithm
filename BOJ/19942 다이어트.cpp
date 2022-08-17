#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

struct Info {
	int mp, mf, ms, mv, cost;
};
Info info[16];
int N, mp, mf, ms, mv;
int res = INF;
map<int, vector<vector<int>>> res_map;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> mp >> mf >> ms >> mv;

	for (int i = 0; i < N; i++) {
		cin >> info[i].mp >> info[i].mf >> info[i].ms >> info[i].mv >> info[i].cost;
	}	// end of for input

	int p, f, s, v, sum;

	for (int i = 1; i < (1 << N); i++) {		// N이 3이면 1 ~ 7 (111) 까지 확인
		p = f = s = v = sum = 0;
		vector<int> index;
		for (int j = 0; j < N; j++) {	// 배열의 인덱스 기준이므로 0부터
			if (i & (1 << j)) {		// j 하나씩 왼쪽으로 이동하면서 총 N까지 가보면서 선택한거 넣는 방식
				p += info[j].mp;
				f += info[j].mf;
				s += info[j].ms;
				v += info[j].mv;
				sum += info[j].cost;
				index.push_back(j + 1);		// j가 인덱스 기준이므로 + 1
			}
		}	// end of for j
		if (p >= mp && f >= mf && s >= ms && v >= mv) {
			if (sum <= res) {	// 같은 가격 여러 개인 경우 사전순으로 정렬해야 하므로 같을때도 포함
				res = sum;
				res_map[res].push_back(index);
			}
		}

	}	// end of for i

	if (res == INF) {
		cout << -1 << "\n";
	}
	else {
		sort(res_map[res].begin(), res_map[res].end());
		cout << res << "\n";
		for (int x : res_map[res][0]) {
			cout << x << ' ';
		}
	}

	return 0;
}