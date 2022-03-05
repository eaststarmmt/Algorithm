#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<pair<int, int>> line;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		line.push_back({ a, b });
	}
	sort(line.begin(), line.end(), cmp);
	int ans = 0;
	int start = line[0].first;
	int end = line[0].second;

	for (int i = 1; i < N; i++) {
		int nowStart = line[i].first;
		int nowEnd = line[i].second;
		if (end > nowStart) {	// ���� ������ ���� ���� ������ ���ۺ��� �ڿ� ������ ��ħ
			end = nowEnd > end ? nowEnd : end;	// ���� ����ƴٴ� �������� ���κ� �÷���
		}
		else {	// ��ġ�� ���� ���
			ans += end - start;		// ���ݱ��� ��� �ִ� ���� ���� ����
			start = nowStart;		// ���� ������ ���� �������� �ٲ���
			end = nowEnd;
		}
	}

	ans += end - start;
	cout << ans << endl;
}