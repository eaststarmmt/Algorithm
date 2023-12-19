#include <string>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

int p[3][3] = {
        {1, 1, 1},
        {5, 1, 1},
        {25, 5, 1},
};
vector<int> a;
int answer = INF;

int calc(int start, int pick) {
    int sum = 0;
    for(int i = start; i < a.size() && i < start + 5; i++) {
        sum += p[pick][a[i]];
    }   // end of for

    return sum;
}

void comb(int start, vector<int>& picks, int sum) {
    if(start >= a.size()) { // 광물 끝까지 다 캔 경우
        answer = min(sum, answer);
        return;
    }

    // 곡괭이 소모가 끝난 경우
    if(!picks[0] && !picks[1] && !picks[2]) {
        answer = min(sum, answer);
        return;
    }

    if(picks[0] != 0) {  // 다이아몬드 곡괭이가 남아 있는 경우
        picks[0]--;
        comb(start + 5, picks, sum + calc(start, 0));
        picks[0]++;
    }

    if(picks[1] != 0) {  // 철 곡괭이가 남아 있는 경우
        picks[1]--;
        comb(start + 5, picks, sum + calc(start, 1));
        picks[1]++;
    }

    if(picks[2] != 0) {  // 돌 곡괭이가 남아 있는 경우
        picks[2]--;
        comb(start + 5, picks, sum + calc(start, 2));
        picks[2]++;
    }

}

int solution(vector<int> picks, vector<string> minerals) {
    for(string s : minerals) {
        if(s == "diamond") a.push_back(0);
        else if(s == "iron") a.push_back(1);
        else a.push_back(2);
    }   // end of for

    comb(0, picks, 0);

    return answer;
}