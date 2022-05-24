#include <iostream>
#include<vector>
using namespace std;
int dp[1001][1001];
int solution(vector<vector<int>> board)
{
	int answer = 0;

	for (int i = 0; i < board[0].size(); i++) {  // 첫 행에서 정사각형의 최대 크기는 자기 자신임
		dp[0][i] = board[0][i];
		if (board[0][i] == 1) answer = 1;
	}   // end of for

	for (int i = 0; i < board.size(); i++) {
		dp[i][0] = board[i][0];
		if (board[i][0] == 1) answer = 1;
	}

	for (int i = 1; i < board.size(); i++) {
		for (int j = 1; j < board[i].size(); j++) {
			if (board[i][j] == 1) {
				dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
				answer = answer < dp[i][j] ? dp[i][j] : answer;
			}
		}   // end of for j
	}   // end of for i

	return answer * answer;
}