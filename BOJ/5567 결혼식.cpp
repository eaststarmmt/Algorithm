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
		scanf("%d %d", &a, &b);		// a �� b ģ�� �����̹Ƿ� ���� �� ����
		list[a].push_back(b);		
		list[b].push_back(a);
	}

	set<int> result;	// �ߺ� ���ֱ� ���� set ���
	
	for (int i = 0; i < list[1].size(); i++) {
		result.insert(list[1][i]);	// 1�� ģ���� �� ����
	}

	for (int i = 0; i < list[1].size(); i++) {	// 1�� ģ���� ��ŭ �ݺ�
		for (int j = 0; j < list[list[1][i]].size(); j++) {		// 1�� ģ���� ģ�� �κ� ����
			if(list[list[1][i]][j] != 1)			// 1�̸� �ڱ� �ڽ������� ���� ���� ����
				result.insert(list[list[1][i]][j]);
		}
	}
	
	printf("%d\n", result.size());

}