#include<iostream>
#include<algorithm>
#define endl "\n"
using namespace std;

int lis[100001];		// lis가 되는 조건 그 자체를 배열로 만듬
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int size = 0;
	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		if (size == 0 || lis[size - 1] < x) {	// 0이면 무조건 넣어야 되고 마지막 숫자보다 크면 그 다음에 넣기
			lis[size++] = x;		// 뒤에다 숫자 넣고 size 1 늘려주기
		}
		else {
			int idx = lower_bound(lis, lis + size, x) - lis;	// 새로 들어온 값이 들어갈 인덱스 위치 찾기. 기존의 값 보다 같거나 큰 숫자중 최소값을 대체
			lis[idx] = x;
		}
	}	// end of input
	
	cout << N - size << endl;
}