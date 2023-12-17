#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long cnt[1004];

long long solution(vector<int> weights) {
	long long answer = 0;

	for (int x : weights) {
		cnt[x]++;
	}

	sort(weights.begin(), weights.end());

	for (int i = 100; i <= 1000; i++) {
		// ������ ������ ���鳢�� ¦ ����
		if (cnt[i] >= 2) {
			answer += cnt[i] * (cnt[i] - 1) / 2;
		}
		// 2�� ����� 3:2�� ����
		if (i * 3 / 2 <= 1000 && cnt[i] && i % 2 == 0 && cnt[i * 3 / 2]) {
			answer += cnt[i] * cnt[i * 3 / 2];
		}

		// 3�� ����̸� 3:4�� ����
		if (i * 4 / 3 <= 1000 && cnt[i] && i % 3 == 0 && cnt[i * 4 / 3]) {
			answer += cnt[i] * cnt[i * 4 / 3];
		}

		// 2�� ������ ��� ���ϱ�
		if (i <= 500) {
			answer += cnt[i] * cnt[i * 2];
		}
	}
	return answer;
}