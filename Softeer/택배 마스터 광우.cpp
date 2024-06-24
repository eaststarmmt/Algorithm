#include<iostream>
#include<algorithm>
#include<vector>
#define INF 1e9
using namespace std;

int N, M, K, res = INF;
vector<int> a;

void calc(vector<int> v) {
	int psum = 0;

	for (int i = 0, idx = 0; i < K; i++) {
		int sum = 0;
		while (sum + v[idx] <= M) {
			sum += v[idx];
			idx = (idx + 1) % v.size();
		}
		psum += sum;
	}
	res = min(res, psum);
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}

	sort(a.begin(), a.end());

	do {
		calc(a);
	} while (next_permutation(a.begin(), a.end()));

	cout << res << '\n';
	return 0;
}