#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

bool cmp_music(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {  // 재생 횟수 같으면 고유번호 낮은 순으로
		return a.first < b.first;
	}
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	unordered_map<string, int> map;

	for (int i = 0; i < genres.size(); i++) {    // 장르 재생 횟수
		map[genres[i]] += plays[i];
	}   // end of for

	vector<pair<string, int>> counting(map.begin(), map.end());
	sort(counting.begin(), counting.end(), cmp);    // 장르 내림차순

	for (int i = 0; i < counting.size(); i++) {
		vector<pair<int, int>> music;   // 고유번호, 횟수
		for (int j = 0; j < genres.size(); j++) {
			if (counting[i].first == genres[j]) {    // 장르 같으면
				music.push_back({ j, plays[j] });
			}
		}
		sort(music.begin(), music.end(), cmp_music);

		answer.push_back(music[0].first);
		if (music.size() > 1) {  // 장르 2개 이상이면 두개 다 저장
			answer.push_back(music[1].first);
		}
	}

	return answer;
}