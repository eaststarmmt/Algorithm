#include <string>
#include <vector>
#include <regex>
using namespace std;
struct Info {
	string head, number, tail;
};

string to_lower(string input) { // 소문자로 바꿔서 정렬에 영향 안미치게 하기
	string s;
	for (int i = 0; i < input.size(); i++) {
		s += tolower(input[i]);
	}
	return s;
}

bool cmp(Info a, Info b) {
	string a_head = to_lower(a.head);
	string b_head = to_lower(b.head);
	if (a_head == b_head) {
		return stoi(a.number) < stoi(b.number);
	}
	return a_head < b_head;
}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<Info> split;
	regex re("\\d");
	for (int i = 0; i < files.size(); i++) {
		string file = files[i];
		bool flag = false;  // number 들어왔는지 확인하기 위함
		int numIdx = -1;
		int tailIdx = file.size();  // 만약 tail이 없는 경우를 생각해서 사이즈를 인덱스로 잡음

		for (int j = 0; j < file.size(); j++) {
			if (regex_match(file.substr(j, 1), re)) {
				if (numIdx == -1) {  // number의 시작 인덱스 저장
					numIdx = j;
				}
				flag = true;
			}
			else if (flag) {   // 이미 앞에서 정규식 맞는경우는 체크해서 자동적으로 아닌 경우만 걸러짐
				tailIdx = j;    // 이 지점이 tail의 시작 인덱스
				break;
			}
		}   // end of for j
		string head = file.substr(0, numIdx);
		string number = file.substr(numIdx, tailIdx - numIdx);
		string tail = file.substr(tailIdx);

		split.push_back({ head, number, tail });
	}   // end of for i

	stable_sort(split.begin(), split.end(), cmp);

	for (int i = 0; i < split.size(); i++) {
		answer.push_back(split[i].head + split[i].number + split[i].tail);
	}
	return answer;
}