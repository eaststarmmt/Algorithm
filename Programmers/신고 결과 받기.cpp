#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer(id_list.size());
	map<string, int> index;         // 이름으로 인덱스 찾기 위해 매핑
	map<string, set<string>> report_map;    // 한명이 여러번 신고한것은 하나로 치므로 set

	for (int i = 0; i < report.size(); i++) {
		stringstream ss(report[i]);
		string a, b;
		ss >> a;
		ss >> b;
		report_map[b].insert(a);
	}   // end of for

	for (int i = 0; i < id_list.size(); i++) {
		index[id_list[i]] = i;
	}

	for (string s : id_list) {
		if (report_map[s].size() >= k) {
			for (string name : report_map[s]) {
				answer[index[name]]++;
			}
		}
	}   // end of for

	return answer;
}