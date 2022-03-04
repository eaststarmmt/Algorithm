#include<cstdio>
#include<set>
#include<vector>
using namespace std;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	vector<vector<int>> list(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);		// a 와 b 친구 관계이므로 양쪽 다 연결
		list[a].push_back(b);		
		list[b].push_back(a);
	}

	set<int> result;	// 중복 없애기 위해 set 사용
	
	for (int i = 0; i < list[1].size(); i++) {
		result.insert(list[1][i]);	// 1의 친구들 다 삽입
	}

	for (int i = 0; i < list[1].size(); i++) {	// 1의 친구들 만큼 반복
		for (int j = 0; j < list[list[1][i]].size(); j++) {		// 1의 친구의 친구 부분 삽입
			if(list[list[1][i]][j] != 1)			// 1이면 자기 자신임으로 포함 하지 않음
				result.insert(list[list[1][i]][j]);
		}
	}
	
	printf("%d\n", result.size());

}