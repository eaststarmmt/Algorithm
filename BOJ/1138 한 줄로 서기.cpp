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
	for (int i = N - 1; i >= 0; i--) {	// �ڿ������� �� ���� ��ŭ �����ؾ� �ٸ��ְ� �������� ��ġ�� ����
		auto iter = result.begin();		//result�� ������ġ �ݺ���
		for (int j = 0; j < input[i]; j++) {
			iter++;					// ���ʿ� �ִ� ��� �� ��ŭ �̵�
		}
		result.insert(iter, i + 1);	// ������ �ε����� i + 1 �� ����ߵ�
	}

	for (auto i : result) {
		printf("%d ", i);
	}
	printf("\n");
}