#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

void comb(int start, int cnt, int& target, string menu, string& order, unordered_map<string, int>& map) {
	if (cnt == target) { // target 만큼 골랐을 때
		map[menu]++;
		return;
	}
	for (int i = start; i < order.size(); i++) {
		comb(i + 1, cnt + 1, target, menu + order[i], order, map);
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	for (int i = 0; i < course.size(); i++) {    // course의 숫자 만큼 먼저 조합 짜기
		unordered_map<string, int> map;
		for (int j = 0; j < orders.size(); j++) {
			if (orders[j].size() < course[i])    // 크기가 course보다 작으면 무시
				continue;
			sort(orders[j].begin(), orders[j].end()); // 알파벳 순서 통일하기 위해 정렬
			comb(0, 0, course[i], "", orders[j], map);
		}
		if (map.empty()) continue;  // map이 비어있으면 info[0] 접근이 불가능
		vector<pair<string, int>> info(map.begin(), map.end());  // map에 저장한거 가져옴
		sort(info.begin(), info.end(), cmp);        // 많이 나온 순으로 정렬
		if (info[0].second < 2) continue;
		answer.push_back(info[0].first);
		for (int j = 1; j < info.size(); j++) {
			if (info[j].second == info[0].second)  // 가장 많은게 같을 때
				answer.push_back(info[j].first);
			else
				break;
		}   // end of for push answer

	}
	sort(answer.begin(), answer.end());
	return answer;
}