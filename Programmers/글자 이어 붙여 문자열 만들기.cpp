#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> index_list) {
	string answer = "";
	for (int x : index_list) {
		answer += my_string[x];
	}
	return answer;
}