#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cctype>
using namespace std;

string lower(string s) {    // 전부 다 소문자로 바꾸기
	string temp;
	for (int i = 0; i < s.size(); i++) {
		temp += tolower(s[i]);
	}
	return temp;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	deque<string> cache;
	for (int i = 0; i < cities.size(); i++) {
		string target = lower(cities[i]);
		auto iter = find(cache.begin(), cache.end(), target);
		if (iter == cache.end()) {   // 캐시에 들어있지 않은 경우
			answer += 5;
		}
		else {    // 들어 있는 경우
			answer++;
			cache.erase(iter);  // 중간에 있는 값 삭제
		}
		cache.push_back(target);
		if (cache.size() > cacheSize) {  // 캐시 크기보다 많아지면 앞에서 삭제
			cache.pop_front();
		}
	}
	return answer;
}