#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int N;

vector<int> solution(vector<string> gems) {
	vector<int> answer(2, 0);
	unordered_map<string, int> gem_map;
	for (int i = 0; i < gems.size(); i++) {
		gem_map[gems[i]] = 0;
	}   // end of for

	N = gem_map.size();
	int start, end;
	start = end = 0;
	int cnt = 0;
	gem_map.clear();

	int min_len = 1e9;
	while (end < gems.size()) {  // end를 기준으로 start를 찾는 방식
		int i;  // end에서 업데이트 되지 못하고 나오는 경우를 잡기 위해 밖에다 선언
		for (i = end; i < gems.size(); i++) {  // N개를 다 포함하는 가장 먼저 나오는 중단지점 찾기
			gem_map[gems[i]]++;
			if (gem_map.size() == N) {   // 다 포함 헀으면 그 위치 저장하고 탈출
				end = i;
				break;
			}
		}   // end of for end
		if (i == gems.size()) {  // end가 갱신되지 않고 끝난 경우는 더 이상 진행하면 안됨
			break;
		}

		for (i = start; i <= end; i++) {
			if (gem_map[gems[i]] == 1) {     // 해당 보석이 한 개 남았으면 여기서 더 이동하면 모든 보석이 포함되지 않으므로 탈출
				start = i;
				break;
			}
			gem_map[gems[i]]--; // 해당 부분은 중복되므로 포함하지 않음
		}

		int len = end - start;
		if (len < min_len) {
			min_len = len;    // 같은 경우에 갱신 안하면 시작 번호가 작은 구간을 저장하게 됨
			answer[0] = start + 1;
			answer[1] = end + 1;
		}
		gem_map.erase(gems[start++]); // start와 end를 한 칸씩 옮겼을때 start 지점에 있던 보석은 포함이 안되므로 맵에서 제거해줘야됨
		end++;
	}   // end of while

	return answer;
}