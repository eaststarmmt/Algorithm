#include <string>
#include <vector>

using namespace std;

void twice(int r, int c, char picture, vector<string>& answer, int k) {
	for (int i = r; i < r + k; i++) {
		for (int j = c; j < c + k; j++) {
			answer[i][j] = picture;
		}
	}
}

vector<string> solution(vector<string> picture, int k) {
	vector<string> answer(picture.size() * k, string(picture[0].size() * k, '.'));

	for (int i = 0; i < picture.size(); i++) {
		for (int j = 0; j < picture[i].size(); j++) {
			twice(i * k, j * k, picture[i][j], answer, k);
		}
	}
	return answer;
}