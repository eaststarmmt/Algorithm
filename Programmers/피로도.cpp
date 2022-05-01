#include <string>
#include <vector>
using namespace std;
bool selected[8];
int R;
int answer;
int seq[8];

void permutation(int start, int cnt, int k, vector<vector<int>>& dungeons) {
	if (R == cnt) {      // 순열 완성 됐을 때
		int temp = 0;   // 몇개 돌 수 있는지 확인하는 변수
		for (int i = 0; i < R; i++) {
			if (k < dungeons[seq[i]][0]) continue;
			k -= dungeons[seq[i]][1];
			temp++;
		}   // end of for     
		answer = temp > answer ? temp : answer;
		return;
	}
	// 단순 순열
	for (int i = 0; i < R; i++) {
		if (selected[i]) continue;
		selected[i] = true;
		seq[cnt] = i;
		permutation(i + 1, cnt + 1, k, dungeons);
		selected[i] = false;
	}
}

int solution(int k, vector<vector<int>> dungeons) {
	R = dungeons.size();
	permutation(0, 0, k, dungeons);
	return answer;
}