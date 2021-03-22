#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int binarySearch(vector<int> vec, int target, int start, int end) {
	int maxDis = 0;
	int cnt, dis, pos;
	while (start <= end) {
		int mid = (start + end) / 2;
		cnt = 1;	//ó�� ��ġ�� �Ѱ��� ��ġ �Ѵ� �����ϰ� 1�� ����
		pos = 0;	//�������� ��ġ�� ������ �ε��� ǥ���� ����
		for (int i = 1; i < vec.size(); i++) {
			dis = vec[i] - vec[pos];
			if (dis >= mid) {
				cnt++;
				pos = i;	//������ �ε��� ǥ��
			}
		}
		if (cnt >= target) {
			start = mid + 1;
			maxDis = max(mid, maxDis);	//mid ���� �������� �ϹǷ� �ּ� �Ÿ��� mid ����
		}

		else end = mid - 1;
			
	}
	return maxDis;
}

int main() {
	int n, c;
	scanf("%d %d", &n, &c);
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	printf("%d \n", binarySearch(vec, c, 0, vec[vec.size() - 1]));	//�̺�Ž���� ���� target�� ������ ������ ��ƾߵ� 
}