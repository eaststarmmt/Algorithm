#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool selected[8];
char friends1[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };  // 따로 저장 안하면 접근하기가 너무 어려움. 이거 friends로 하면 런타임 에러남. 이유는 모르겠음
int answer;
void permutation(vector<string> data, int cnt, char line[]) {
	if (cnt == 8) {
		for (int i = 0; i < data.size(); i++) {
			char from = data[i][0];     // 원하는 놈
			char to = data[i][2];       // 타겟
			char oper = data[i][3];     // 연산자
			int val = 1 + (data[i][4] - '0');      // 조건에 해당하는 값. 딱 붙어있는게 1이기 때문에 +1 해줘야 됨

			int from_idx, to_idx;
			from_idx = to_idx = -1;     // 둘다 -1로 초기화
			for (int j = 0; j < 8; j++) {    // 8명 위치 일일히 찾아서 조건 맞는지 확인
				if (line[j] == from) from_idx = j;
				if (line[j] == to) to_idx = j;
				if (from_idx != -1 && to_idx != -1) break;
			}   // end of for 8
			// 아닌 경우 return 해버려서 카운팅 안되게 막음
			if (oper == '=' && val != abs(from_idx - to_idx)) return;
			if (oper == '<' && val <= abs(from_idx - to_idx)) return;
			if (oper == '>' && val >= abs(from_idx - to_idx)) return;
		}   // end of for data
		answer++;    // loop을 무사히 빠져 나왔으면 경우의 수에 하나 추가
		return;     // 지금 경우는 카운팅 했으므로 순열에 관여하지 않게 return
	}

	for (int i = 0; i < 8; i++) {    // 순열 만들기
		if (selected[i]) continue;   // 이미 선택했다면 무시
		selected[i] = true;
		line[cnt] = friends1[i];     // cnt를 인덱스로 사용해서 셔플
		permutation(data, cnt + 1, line);
		selected[i] = false;
	}
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
	answer = 0;
	char line[8] = { 0 };
	permutation(data, 0, line);
	return answer;
}