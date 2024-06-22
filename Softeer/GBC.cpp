#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> v1, v2;
int N, M, res;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = 0; j < a; j++) {
			v1.push_back(b);
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = 0; j < a; j++) {
			v2.push_back(b);
		}
	}

	for (int i = 0; i < 100; i++) {
		res = max(res, v2[i] - v1[i]);
	}
	
	cout << res << '\n';
}