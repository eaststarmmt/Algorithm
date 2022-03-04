#include<iostream>
#define endl "\n"
using namespace std;
int graph[401][401];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = -1;	// [x][y]�� x�� ������ -1 y�� ������ 1
		graph[b][a] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][k] != 0 && graph[i][k] == graph[k][j]) {	// �߰� ��ΰ� 0�� �ƴϰ� ���� ������ ���� ���
					graph[i][j] = graph[i][k];						// [i][j]�� [i][k] �� ����
				}
			}
		}
	}

	int S;
	cin >> S;
	for (int i = 0; i < S; i++) {
		int a, b;
		cin >> a >> b;
		cout << graph[a][b] << endl;
	}
}