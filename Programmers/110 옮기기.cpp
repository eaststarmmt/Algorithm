#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> str) {
	vector<string> answer;
	for (string s : str) {
		stack<char> stk;
		int cnt = 0;    // 110 카운팅 변수
		for (char c : s) {
			if (stk.size() >= 2 && c == '0') {   // 0이 나오면 110인지 확인하기
				char c1 = stk.top();
				stk.pop();
				char c2 = stk.top();
				stk.pop();
				if (c1 == '1' && c2 == '1') {    // 110인 경우 카운팅 하고 다시 넣지 않음
					cnt++;
					continue;
				}
				stk.push(c2);   // 110 아닌 경우 다시 넣기
				stk.push(c1);
			}
			stk.push(c);
		}   // end of for s

		string temp;
		while (!stk.empty()) {
			temp += stk.top();
			stk.pop();
		}   // end of while
		reverse(temp.begin(), temp.end());    // 스택에 뒤집어 들어 왔으니 다시 뒤집어 줌

		int idx = 0;
		string res;

		for (; idx < temp.size(); idx++) {   // 10 11 체크해야 하므로 size - 1 까지만
			if (idx == temp.size() - 1) {
				if (temp[idx] == '0') res += temp[idx++];	// 마지막 자리가 0이면 담기
				break;
			}
			if (temp[idx] == '1'&& temp[idx + 1] == '1') break;     // 11 나오는건 1이 세개 이상 이므로 110 뒤로 미뤄야 되므로 stop
			res += temp[idx];   // 1 10 01 은 담기
		}   // end of for temp

		for (int i = 0; i < cnt; i++) {  // 110 채워주기
			res += "110";
		}

		res += temp.substr(idx);   // 나머지 뒷부분 다 넣어주기

		answer.push_back(res);
	}   // end of for str
	return answer;
}