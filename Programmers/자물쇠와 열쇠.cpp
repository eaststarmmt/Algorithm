#include <string>
#include <vector>
#include <cstring>
using namespace std;

int key_copy[58][58];
int groove;
int N, Lock;
void turn_key(vector<vector<int>>& key) {
	vector<vector<int>> temp;
	temp.assign(key.begin(), key.end());
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			key[j][N - 1 - i] = temp[i][j];
		}
	}
}

void setKey(vector<vector<int>>& key) {     // key를 중간에 넣음
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			key_copy[Lock - 1 + i][Lock - 1 + j] = key[i][j];   // 자물쇠를 이동하면서 확인하기 때문에 자물쇠 크기를 기준으로 잡음
		}
	}
}

bool check(vector<vector<int>>& lock, int row, int col) {
	int cnt = 0;
	for (int i = 0; i < lock.size(); i++) {
		for (int j = 0; j < lock.size(); j++) {
			if (key_copy[row + i][col + j] == 1) {  // 확인하는 범위를 움직임
				if (lock[i][j] == 1 && key_copy[row + i][col + j] == 1)
					return false;
				if (lock[i][j] == 0 && key_copy[row + i][col + j] == 1)
					cnt++;
			}
		}
	}
	if (cnt != groove) {
		return false;
	}
	return true;
}

bool open_check(vector<vector<int>>& key, vector<vector<int>>& lock) {
	memset(key_copy, 0, sizeof(key_copy));
	setKey(key);
	for (int i = 0; i < Lock * 2 - 2; i++) {       // 자물쇠를 기준으로 검사해야됨
		for (int j = 0; j < Lock * 2 - 2; j++) {
			if (check(lock, i, j)) {
				return true;
			}

		}   // end of for j
	}   // end of for i
	return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	N = key.size();
	Lock = lock.size();
	for (int i = 0; i < lock.size(); i++) {
		for (int j = 0; j < lock[i].size(); j++) {
			if (lock[i][j] == 0) {
				groove++;
			}
		}   // end of for j
	}   // end of for i
	if (groove == 0) return true;
	for (int i = 0; i < 4; i++) {
		if (open_check(key, lock)) {
			return true;
		}
		if (i != 3) {
			turn_key(key);
		}
	}
	return answer;
}