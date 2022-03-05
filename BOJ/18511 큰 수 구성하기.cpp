#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n , k, result;		// ��ͷ� ������ ���� �������� ����
vector<int> vec;		// k�� ���ҵ�

void recursive(int x) {
	if (n < x) return;	// x �� 0���� ũ�� ���ǿ� �ȸ����Ƿ� Ż��
	result = result < x ? x : result;	// result���� Ȯ�� �Ϸ��� x���� ũ�� x���� �־���. �ᱹ n������ ���� �� �ִ밪�� ���´�
	for (int i = 0; i < k; i++) {
		recursive(10 * x + vec[i]);		// x�� 10�� ���ؼ� ���ڸ��� �ø��� k�� ���Ҹ� �ϳ��� �ٿ��� Ȯ���ϴ� ���
	}

}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end(), greater<int>());	// ������������ ����
	recursive(0);
	printf("%d\n", result);
}