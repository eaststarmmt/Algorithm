#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearch(vector<int> input, int start, int end, int target) {
	int maxDis = 0;		// ���� ū �ּ� �Ÿ�
	while (start <= end) {
		int mid = (start + end) / 2;	// �ּҰŸ��� �߰� ������ Ž��. �������� �� ���� �߰����� Ž���ϴ� ��� �̿�
		int last = 0;					// �ֱٿ� �����Ⱑ ��ġ�� ���� �ε���
		int cnt = 1;					// ��ġ�� ������ ����
		for (int i = 1; i < input.size(); i++) {
			int dis = input[i] - input[last];	// ������ ��ġ�� ���� ���� ��ġ�� �Ÿ�
			if (dis >= mid) {			// mid���� ū ��츸 ��ġ
				cnt++;
				last = i;
			}
			
		}
		if (cnt >= target) {		// target �� ���� �̻� ��ġ �� ���
			start = mid + 1;		// start ���� �÷��� mid ���� Ű��
			maxDis = mid > maxDis ? mid : maxDis;	// target ��ŭ ��ġ �����ϴ� ���̱� ������ �ִ��ּҰŸ� ����
		}
		else end = mid - 1;			// end ���� �ٿ��� mid ���� ����		
	}
	return maxDis;
}

int main() {

	int N, C;
	scanf("%d %d", &N, &C);
	vector<int> input;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		input.push_back(x);
	}
	sort(input.begin(), input.end());
	printf("%d", binarySearch(input, 0, input[input.size() - 1], C));	// �������� input�� ������� ������ 0���� �ؾ� �������� ��Ȯ�� �߰����� ����

}