#include <string>
#include <vector>

using namespace std;
string day[] = {"THU","FRI","SAT", "SUN","MON","TUE","WED"};
int month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string solution(int a, int b) {
    string answer = "";
    int today = 0;
    for(int i = 0; i < a - 1; i++) {
        today += month[i];
    }
    today += b;
    answer = day[today % 7];
    return answer;
}