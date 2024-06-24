#include<iostream>
#include<string>
#include<algorithm>


using namespace std;

int N, K;
string a;
int visited[20004];

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> a;

	int res = 0;

	for (int i = 0; i < N; i++) {
		if (a[i] == 'H') continue;
		for (int j = i - K; j <= i + K; j++) {
			if (j < 0 || j >= N) continue;
			if (a[j] == 'P') continue;
			if (visited[j]) continue;
			res++;
			visited[j] = 1;
			break;
		}
	}
	cout << res << '\n';
	return 0;
}