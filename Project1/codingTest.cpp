#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

bool isPossible(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t, long long mid) {
	long long gold = 0;     // ������ ������ ��
	long long silver = 0;
	long long goldSilver = 0;
	for (int i = 0; i < g.size(); i++) {
		long long rtt = t[i] * 2;       // �պ� �ð�
		long long cnt = mid / rtt;      // �־��� �ð� / �պ��ð�
		if (mid % rtt >= t[i]) cnt++;    // �������� �ü� �ִ� �ð��̸� ī����. ���ư� �ʿ� �����Ƿ�
		long long send = w[i] * cnt;    // ������ Ƚ�� * �ѹ��� ���� �� �ִ� �ִ� ���Ը� ���� �󸶳� �޾Ҵ��� üũ
		gold += min((long long)g[i], send); // �ִ� ������ ���԰� ���� ���Ժ��� ������ �ȵ�. �ִ밪 �����ֱ�
		silver += min((long long)s[i], send);
		goldSilver += min((long long)s[i] + g[i], send);   // �� �� �����ϰ� ���� ��ģ���� ���Ա��� Ȯ���ؾ� ��
	}

	if (gold >= a && silver >= b && goldSilver >= a + b) return true;    // ������ �ʿ��� �� �̻� ���� �����ϸ� true
	return false;

}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
	long long start = 0;
	long long end = 10e14 * 4;   // ���� ���� �� �־��� ���
	long long answer = end;

	while (start <= end) {
		long long mid = (start + end) / 2;
		if (isPossible(a, b, g, s, w, t, mid)) {     // mid �ȿ� �ű� �� �ִ� ���
			answer = mid < answer ? mid : answer;
			end = mid - 1;
		}
		else start = mid + 1;
	}
	return answer;
}