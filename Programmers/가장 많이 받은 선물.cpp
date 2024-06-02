#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

map<string, int> m; // 인덱스 찾을 맵. <친구, 인덱스>
int graph[51][51];  // 그래프 형태로 [준 친구][받은 친구] - 개수 형태로 저장
int give[51];   // 준 선물 개수
int take[51];   // 받은 선물 개수
int cnt[51];    // 이번에 받은 선물 카운팅

pair<string, string> split(string s) {
	stringstream ss(s);
	pair<string, string> p;
	ss >> p.first;
	ss >> p.second;

	return p;
}

int solution(vector<string> friends, vector<string> gifts) {
	int answer = 0;

	for (int i = 0; i < friends.size(); i++) {   // map에 인덱스 저장
		m[friends[i]] = i;
	}   // end of for

	for (int i = 0; i < gifts.size(); i++) {
		pair<string, string> p = split(gifts[i]); // <선물 준 친구, 받은 친구>
		graph[m[p.first]][m[p.second]]++;   // 준 친구, 받은 친구 카운팅
		give[m[p.first]]++;
		take[m[p.second]]++;
	}   // end of for

	for (int i = 0; i < friends.size() - 1; i++) {
		for (int j = i + 1; j < friends.size(); j++) {
			if (i == j) continue;    // 자기 자신 무시

			string first = friends[i];     // 첫번째 친구 이름으로 쓸 중간변수
			string second = friends[j];    // 두번째 친구 이름으로 쓸 중간변수
			// 인덱스 맵에서 가져옴
			int first_idx = m[first];
			int second_idx = m[second];
			// 선물 지수 계산
			int first_score = give[first_idx] - take[first_idx];
			int second_score = give[second_idx] - take[second_idx];

			if (graph[first_idx][second_idx] == graph[second_idx][first_idx]) {  // 선물 주고 받은 갯수 같은 경우
				if (first_score == second_score) continue;   // 지수도 같으면 무효
				else if (first_score > second_score) cnt[first_idx]++;   // 둘중에 지수 높은 쪽이 받기
				else cnt[second_idx]++;
			}
			else if (graph[first_idx][second_idx] > graph[second_idx][first_idx]) cnt[first_idx]++;    // 둘이 주고 받은 선물 개수 비교해서 많이 준 쪽이 받기
			else cnt[second_idx]++;
		}   // end of for j
	}   // end of for i

	answer = *max_element(cnt, cnt + 51);
	return answer;
}