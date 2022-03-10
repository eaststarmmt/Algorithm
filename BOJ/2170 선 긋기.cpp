#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct Line {
	int x, y;
};

bool cmp(Line a, Line b) {	// ���� �� �������� ��������
	return a.x < b.x;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<Line> dots;
	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		dots.push_back({ x, y });
	}	// end of input

	sort(dots.begin(), dots.end(), cmp);

	int ans = 0;
	int left = dots[0].x;		// ���� Ȯ���ϰ� �ִ� ���� ���� ��ǥ
	int right = dots[0].y;		// ���� Ȯ���ϰ� �ִ� ���� ������ ��ǥ

	for (int i = 1; i < N; i++) {
		if (dots[i].x <= right) {	// ���� ���� �ִ� �� ������ ���� �׸� ���� ������ ���
			right = dots[i].y > right ? dots[i].y : right;	// ���� ���̰� �ִ밡 �ǵ��� ����
		}
		else {		// ���� �׸� ���� ������ ���� �ʴ� ���
			ans += right - left;	// �� ���� �����ֱ�
			left = dots[i].x;		// ���ο� ���� ���� ��ǥ ����
			right = dots[i].y;		// ���ο� ���� ������ ��ǥ ����
		}
	}	// end of calc without Nth line
	ans += right - left;
	printf("%d\n", ans);
}