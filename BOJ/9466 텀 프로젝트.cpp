#include<iostream>
#include<set>
#include<cstring>
#define endl "\n"
using namespace std;

int N, result;
int want[100001];
bool visited[100001];	// �湮 �� ��ü�� �ߴ��� Ȯ�ο�
bool team[1000001];		// ���� �Ǵ��� Ȯ�� �ߴ��� Ȯ�ο�. �ϴ� �ѹ� ��͸� Ÿ�� ���� ��������� �ƴϴ� ����� ��

void dfs(int now) {
	visited[now] = true;
	if (!visited[want[now]]) dfs(want[now]);	// �湮�� ���� ���ٸ� ��ͷ� ��
	else {
		if (!team[want[now]]) {		// �湮�� �ߴµ� ���� �Ǵ��� Ȯ���� ���� ���ٸ� ����Ŭ�� �������Ƿ� ���� �ϼ�
			while (!team[now]) {	
				team[now] = true;	// ���� �Ǿ����Ƿ� ǥ��
				now = want[now];	// ���� ���ϴ� ������� now �̵�
				result--;			// �Ѹ� ���� �������Ƿ� ��ü���� 1 ����
			}
		}
	}
	team[now] = true;	// ���� �ȵǴ��� ���⼭ ǥ�� �ϸ� ���� �ȵǴ� �Ǵ� ���̻� Ȯ���� �ʿ䰡 ����
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> N;
		result = N;
		memset(visited, false, sizeof(visited));	
		memset(team, false, sizeof(team));
		for (int i = 1; i <= N; i++) {
			cin >> want[i];
		}
		for (int i = 1; i <= N; i++) {
			if (team[i] || visited[i]) continue;	// �湮������ ����
			dfs(i);
		}
		cout << result << endl;
	}
}