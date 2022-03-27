#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

void comb(int start, int cnt, int& target, string menu, string& order, unordered_map<string, int>& map) {
	if (cnt == target) { // target ��ŭ ����� ��
		map[menu]++;
		return;
	}
	for (int i = start; i < order.size(); i++) {
		comb(i + 1, cnt + 1, target, menu + order[i], order, map);
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	for (int i = 0; i < course.size(); i++) {    // course�� ���� ��ŭ ���� ���� ¥��
		unordered_map<string, int> map;
		for (int j = 0; j < orders.size(); j++) {
			if (orders[j].size() < course[i])    // ũ�Ⱑ course���� ������ ����
				continue;
			sort(orders[j].begin(), orders[j].end()); // ���ĺ� ���� �����ϱ� ���� ����
			comb(0, 0, course[i], "", orders[j], map);
		}
		if (map.empty()) continue;  // map�� ��������� info[0] ������ �Ұ���
		vector<pair<string, int>> info(map.begin(), map.end());  // map�� �����Ѱ� ������
		sort(info.begin(), info.end(), cmp);        // ���� ���� ������ ����
		if (info[0].second < 2) continue;
		answer.push_back(info[0].first);
		for (int j = 1; j < info.size(); j++) {
			if (info[j].second == info[0].second)  // ���� ������ ���� ��
				answer.push_back(info[j].first);
			else
				break;
		}   // end of for push answer

	}
	sort(answer.begin(), answer.end());
	return answer;
}