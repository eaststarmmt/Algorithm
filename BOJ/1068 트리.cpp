#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[54];
int N, root, rem, ans;

int dfs(int x) {
	int ret = 0;
	int child = 0;
	for (int i = 0; i < tree[x].size(); i++) {
		if (tree[x][i] == rem) continue;
		ret += dfs(tree[x][i]);	 // 자식들 결과 가지고 가기
		child++;
	}
	if (child == 0) return 1;
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {	// tree[입력값] = i 형태로 저장
		int x;
		cin >> x;
		if (x == -1) {
			root = i;
			continue;
		}
		tree[x].push_back(i);
	}	// end of for

	cin >> rem;
	if (rem == root) {
		cout << 0 << "\n";
	}
	else {
		cout << dfs(root) << "\n";
	}
	return 0;
}