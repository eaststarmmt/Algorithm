#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node {
	int prev = -1, next = -1, val = -1;
};

Node table[1000000];

string solution(int n, int k, vector<string> cmd) {
	string answer(n, 'O');

	for (int i = 0; i < n; i++) {
		table[i].val = i;
		table[i].prev = i - 1;
		if (i < n - 1) {
			table[i].next = i + 1;
		}
	}   // end of for

	stack<Node> del;    // for 복구

	for (int i = 0; i < cmd.size(); i++) {
		if (cmd[i][0] == 'U') {
			int move = stoi(cmd[i].substr(2));
			for (int i = 0; i < move; i++) {
				k = table[k].prev;
			}
		}
		else if (cmd[i][0] == 'D') {
			int move = stoi(cmd[i].substr(2));
			for (int i = 0; i < move; i++) {
				k = table[k].next;
			}
		}
		else if (cmd[i] == "C") {   // 삭제
			// 가리키는 다음 인덱스와 이전 인덱스를 변경해줌
			answer[k] = 'X';
			int prev = table[k].prev;
			int next = table[k].next;
			table[prev].next = next;
			table[next].prev = prev;
			del.push(table[k]);    // 기존의 next와 prev를 그대로 가져가서 복구할 때 이용
			k = next == -1 ? prev : next;   // 끝에 있으면 prev
		}
		else {      // 연결리스트 개념으로 prev랑 next만 다시 이어줌
			answer[del.top().val] = 'O';
			Node node = del.top();
			del.pop();
			node.next = table[node.prev].next;
			node.prev = table[node.next].prev;
			table[node.prev].next = node.val;
			table[node.next].prev = node.val;
		}
	}

	return answer;
}