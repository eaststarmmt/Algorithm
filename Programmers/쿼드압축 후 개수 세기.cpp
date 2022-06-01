#include <string>
#include <vector>

using namespace std;
void divideNCon(vector<vector<int>>& arr, vector<int>& answer, int r, int c, int size) {
	int target = arr[r][c];
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (target != arr[i][j]) {       // 숫자가 달라서 나눠지므로 카운팅 하지 않도록 return 해야 됨
				divideNCon(arr, answer, r, c, size / 2);        // 4등분으로 나눔
				divideNCon(arr, answer, r + size / 2, c, size / 2);
				divideNCon(arr, answer, r, c + size / 2, size / 2);
				divideNCon(arr, answer, r + size / 2, c + size / 2, size / 2);
				return;
			}
		}   // end of for j
	}   // end of for i
	answer[target]++;
}
vector<int> solution(vector<vector<int>> arr) {
	vector<int> answer(2);
	divideNCon(arr, answer, 0, 0, arr.size());
	return answer;
}