#include<stdio.h>
#include<vector>
#include<queue>
#define MAX 9876543210	// 바텀업때 쓰려고 했으나 필요 없어짐. 그러나 이걸로 long long 써야되는걸 알았음
using namespace std;

// 바텀업으로 시도했다가 조짐.
// 큐를 사용했는데 이거 brute force의 의도에 맞는지는...
int main() {
	
	int N;
	scanf("%d", &N);
	vector<long long> decrease;
	queue<long long> queue;
	
	for (int i = 0; i <= 9; i++) {	// 0 ~ 9 까지 한자리 수는 다 넣어둔다.
		decrease.push_back(i);
		queue.push(i);
	}

	while (queue.size() > 0) {		// 큐가 빌 때까지 계속 반복
		if (decrease.size() == N) break;	// 원하는 순서의 값이 구해지면 중단
		long long x = queue.front();		// queue는 현재 오름차순으로 들어가있음. 
		queue.pop();
		for (int i = 0; i < x % 10; i++) {	// x의 1의자리수보다 크지 않은 숫자를 뒤에 붙여줌.
			long long y = x * 10 + i;		// x의 값에 10을 곱해서 자리수를 올려주고 기존의 수보다 작은 수를 뒤에 붙여줌
			decrease.push_back(y);
			queue.push(y);				// 이 값을 넣는 이유는 줄어드는 숫자가 완성 된 값에 1의 자리에 더 작은 숫자를 붙여주는 작업을 반복하기 위함
		}
	}
	
	if (N > decrease.size())	// 한자리수 숫자때매 같을때로 하면 안됨
		printf("%d\n", -1);
	else
		printf("%lld\n", decrease[N - 1]);
}