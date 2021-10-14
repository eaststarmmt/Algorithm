#include<cstdio>
#include<vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<int> input;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		input.push_back(x);
	}
	
	vector<int> result;
	for (int i = N - 1; i >= 0; i--) {	// 뒤에서부터 현 순서 만큼 적용해야 다른애가 들어왔을때 겹치지 않음
		auto iter = result.begin();		//result의 시작위치 반복자
		for (int j = 0; j < input[i]; j++) {
			iter++;					// 왼쪽에 있는 사람 수 만큼 이동
		}
		result.insert(iter, i + 1);	// 저장은 인덱스인 i + 1 을 해줘야됨
	}

	for (auto i : result) {
		printf("%d ", i);
	}
	printf("\n");
}