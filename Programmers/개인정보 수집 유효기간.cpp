#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

map<char, int> terms_map;
int today_int;

void set_pri(string s) {
    stringstream stream(s);
    string name;
    string term;

    stream >> name;
    stream >> term;

    terms_map[name[0]] = stoi(term);
}

int string_to_int(string s) {
    int year = stoi(s.substr(0, 4));
    int month = stoi(s.substr(5, 2));
    int day = stoi(s.substr(8, 2));

    int res = year * 12 * 28 + (month - 1) * 28 + day;

    return res;
}

bool check(string s) {
    bool res = false;

    char type = s.back();
    int term = terms_map[type];

    int privacy = string_to_int(s) + (term * 28 - 1);

    if (privacy < today_int) res = true;

    return res;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    for (string s : terms) { // 약관 별 기간
        set_pri(s);
    }   // end of for terms

    today_int = string_to_int(today);   // 확인할 기준점

    for (int i = 0; i < privacies.size(); i++) {
        string s = privacies[i];

        if (!check(s)) continue;
        answer.push_back(i + 1);
    }

    return answer;
}