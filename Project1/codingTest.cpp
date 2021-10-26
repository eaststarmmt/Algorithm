#include<iostream>
#include<algorithm>
#define endl "\n"
#define INF 1e9
using namespace std;

int graph[101][101];
int counting[101];

void print(int N, int M) {	// �׳� �ǹ� ���� graph ���� ���
	cout << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {	// ũ�� �۴� ������ ���⸸�� �־����
		int a, b;
		cin >> a >> b;		
		graph[a][b] = 1;	// a���忡�� ū ��� 1�� ����	
		graph[b][a] = 2;	// b���忡�� ���� ��� 2�� ����
	}

	for (int k = 1; k <= N; k++) {	// �÷��̵� ���� ����. �׷��� �ִ� �Ÿ��� �ƴ϶� ���⸸�� ����
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][k] != 0 && graph[i][k] == graph[k][j])	// i���� k�� �񱳰� �̷������ ���� �����϶�
					graph[i][j] = graph[i][k];	// ������ 1�̾��ٰ� 2�� �ٲ��� ����. �� ���⿡ ���� Ŀ���� �۾����� �� ���� ����
			}
		}
	}

	//print(N, M);

	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] == 0) cnt++;	// 0�� �ƴϸ� �񱳰� �̷����ٴ� �ǹ�
		}
		cout << cnt - 1 << endl;	// �ڱ� �ڽ��� ���� �ؾ� �ǹǷ� -1 �ؼ� ���
	}
}