#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
using namespace std;

int N, M;
vector<int> pocket;
int sum;
int binarySearch(int start, int end) {
	int result = sum;	// ����� ����� ������ ����
	while (start <= end) {
		int mid = (start + end) / 2;	// �갡 �������� K �� �����ϴ� �ݾ�
		int haveMoney = mid;
		int cnt = 1;			// ���� ī����
		for (int i = 0; i < N; i++) {
			if (haveMoney < pocket[i]) {	// �������� �� ������ �ٽ� mid ��ŭ �����ְ� ī����
				cnt++;
				haveMoney = mid;
			}
			haveMoney -= pocket[i];		// ���������� �ʿ� �ݾ׸�ŭ ����
			
		}
		if (cnt > M) start = mid + 1;	//	cnt�� M���� ũ�� ���信 ������ ����
		else {							// ���찡 M ���� ���� �����ϴ��� 
			end = mid - 1;				// M�� ���߷��� �ٽ� �����ϴ� ���°��� ������ �ִٰ� ����
			result = mid < result ? mid : result;	// �� M���� ���� ��쵵 ������ �� �� �ֱ⿡ result �� ���ſ� ������ ��
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int maxValue = 0;				// ���� ��� ���� �ּҰ����� ������ ��
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		pocket.push_back(x);
		sum += x;					// ���� �ִ밪���� ������ ��
		maxValue = x > maxValue ? x : maxValue;
	}

	cout << binarySearch(maxValue, sum) << endl;
}