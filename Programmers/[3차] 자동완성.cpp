#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// 나중에 트라이로 풀어볼것

int solution(vector<string> words) {
	int answer = 1;		// 맨 첫번째 단어에 pre 인덱스가 0이라 1이 더 적게 출력됨
	sort(words.begin(), words.end());

	int pre = 0;	// 이전 단어 저장한 인덱스
	string preWord = words[0];

	for (int cur = 1; cur < words.size(); cur++) {

		int i = 0;
		string curWord = words[cur];

		for (; i < curWord.size(); i++) {
			if (i >= preWord.size()) {	// 현재 보고 있는 단어의 인덱스가 이전 단어의 길이만큼 간 경우
				answer += preWord.size() - pre - 1;	// 이전 단어 길이만큼 저장. 단어 5개 저장해야 되는데 이전에 3개 했으면 pre가 인덱스라 2 이므로 1 더 빼줘야 5가 됨
				answer += i + 1;	// 현재 보고 있는 단어는 i 까지 왔으므로 i + 1 개
				break;
			}
			// 길이는 아직 안넘어간 상태
			if (curWord[i] != preWord[i]) {		// 단어 서로 다른 경우
				if (i > pre) {	// 이전에 저장한게 i 보다 작았을 경우
					answer += i - pre;	// pre 저장 위치 갱신 되어 이번 인덱스까지 더 횟수 늘어남
				}
				answer += i + 1;	// 현재 위치까지 개수 이므로 인덱스 + 1
				break;
			}
		}	// end of for curWord

		pre = i;	// 이전 단어 어디까지 검색으로 저장했는지 확인하기 위함. 그래야 뒤에 단어 더 필요하면 계산 가능
		preWord = words[cur];

	}	// end of for words
	return answer;
}