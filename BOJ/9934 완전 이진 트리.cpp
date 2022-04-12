#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

int tree[1024];
int tree_size;
int K;
vector<int> res[10];
void search(int start, int end, int level) {
	if (level == K)		// 마지막 레벨을 넘어가면 종료
		return;	
	
	int mid = (start + end) / 2;
	res[level].push_back(tree[mid]);	// 중위 순회에 완전 이진트리 형태 이므로 중간에 있는 값이 무조건 루트임
	search(start, mid - 1, level + 1);
	search(mid + 1, end, level + 1);
}

int main() {
	scanf("%d", &K);
	tree_size = pow(2, K) - 1;	// 원소 개수 계산
	for (int i = 0; i < tree_size; i++) {
		scanf("%d", &tree[i]);
	}	// end of for
	search(0, tree_size, 0);
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < res[i].size(); j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
}