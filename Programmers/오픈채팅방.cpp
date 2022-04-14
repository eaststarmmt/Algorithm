#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<string> id_list;		// 들어오거나 나간 경우 id를 저장할 벡터
unordered_map<string, string> nicks;	// 아이디랑 닉네임 매핑시키기 위해 저장할 맵
vector<string> answer;

void stringTokenizer(string s) {
	stringstream stream(s);
	int idx = 0;
	string id, nick;
	bool flag = false;
	while (getline(stream, s, ' ')) {    // 공백 기준으로 문자열 나눔. Leave의 경우 idx가 2일때 while문이 돌지 않음
		if (idx == 0) {
			if (s == "Enter") {
				answer.push_back("님이 들어왔습니다.");    // 일단 이걸로 저장
				flag = true;  // 아이디 저장해야 되는 플래그    
			}
			else if (s == "Leave") {
				answer.push_back("님이 나갔습니다.");    // 일단 이걸로 저장
				flag = true;  // 아이디 저장해야 되는 플래그
			}
		}
		else if (idx == 1) {
			id = s;         // 두번째 단어 아이디에 넣기

			if (flag) {       // 들어오거나 나간 경우 아이디 저장
				id_list.push_back(id);
			}

		}
		else if (idx == 2) {
			nick = s;       // 세번째 단어 닉네임에 넣기
			nicks[id] = nick;   // 아이디 기준으로 닉네임 맵에 저장해서 마지막 값으로 계속 갱신됨
		}
		idx++;
	}   // end of while stream

	return;
}

vector<string> solution(vector<string> record) {

	for (int i = 0; i < record.size(); i++) {
		stringTokenizer(record[i]);
	}   // end of for

	for (int i = 0; i < answer.size(); i++) {    // answer에 id 추가
		answer[i] = nicks[id_list[i]] + answer[i];
	}
	return answer;
}