#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct balloon {
	int index, num;
};

bool cmp(balloon a, balloon b) {
	return a.num < b.num;
}
int solution(vector<int> a) {
	int answer = 2;
	if (a.size() <= 2) return a.size();
	vector<balloon> balloons;
	for (int i = 0; i < a.size(); i++) {
		balloons.push_back({ i, a[i] });  // index�� ���� ����
	}
	sort(balloons.begin(), balloons.end(), cmp);
	// ���� ���� �� �ΰ��� ���Ѽ� ���Ѽ� ����. �� ���̿� �� ������ ��Ƴ��� �� ����
	int lower = balloons[0].index < balloons[1].index ? balloons[0].index : balloons[1].index;
	int upper = balloons[0].index > balloons[1].index ? balloons[0].index : balloons[1].index;
	// �� ���� �������ڰ� ������ �� �� ����
	for (int i = 2; i < balloons.size(); i++) {
		if (balloons[i].index > lower && balloons[i].index < upper)  // ���̿� �������� ������ ����
			continue;
		if (balloons[i].index < lower)   // �ε����� ���Ѽ� ���� ������ ���Ѽ� ����
			lower = balloons[i].index;
		else if (balloons[i].index > upper)  // ���Ѽ����� ũ�� ���Ѽ� ����
			upper = balloons[i].index;
		answer++;       // contiune�� �ɷ����� �ʾ����� ��Ƴ������Ƿ� ī����
	}
	return answer;
}