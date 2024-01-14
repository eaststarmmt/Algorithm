#include <string>
#include <vector>

using namespace std;
bool visited[130];

string solution(string my_string) {
	string answer = "";
	for (char c : my_string) {
		if (visited[c]) continue;
		answer += c;
		visited[c] = 1;
	}
	return answer;
}