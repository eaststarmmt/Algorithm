#include <string>
#include <vector>

using namespace std;
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;

	for (int i = 0; i < arr1.size(); i++) {    // 총 arr1의 행의 개수만큼 진행
		vector<int> row;
		for (int j = 0; j < arr2[0].size(); j++) {  // arr2의 열의 개수만큼 계산 해야 한 행이 완성 됨
			int temp = 0;

			for (int k = 0; k < arr1[0].size(); k++) {   // arr1의 열
				temp += arr1[i][k] * arr2[k][j];
			}   // end of 
			row.push_back(temp);

		}   // end of for column of arr2
		answer.push_back(row);
	}   // end of row of arr1
	return answer;
}