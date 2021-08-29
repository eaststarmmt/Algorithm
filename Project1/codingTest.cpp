#include<cstdio>
#include<vector>
using namespace std;

int main() {
	
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {

		int N;
		scanf("%d", &N);
		vector<int> day;
		for (int i = 0; i < N; i++) {
			int x;
			scanf("%d", &x);
			day.push_back(x);
		}
		int max = day[N - 1];
		long long result = 0;
		for (int i = N - 1; i >= 0; i--) {	// �ڿ������� ���� Ȯ��
			if (max > day[i]) result += max - day[i];
			else max = day[i];
		}
		printf("#%d %lld\n", test, result);
	}
}
