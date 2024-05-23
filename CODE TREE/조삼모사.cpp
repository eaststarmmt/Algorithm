#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 1e9
using namespace std;

int a[24][24], N, res = INF;

int get_score(vector<int>& morning, vector<int>& evening) {
    pair<int, int> score;

    for(int i = 0; i < morning.size(); i++) {
        for(int j = 0; j < morning.size(); j++) {
            score.first += a[morning[i]][morning[j]];
            score.second += a[evening[i]][evening[j]];
        }   // end of for j
    }   // end of for i

    return abs(score.first - score.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> a[i][j];
        }   // end of for j
    }   // end of for i

    for(int i = 1; i < (1 << N); i++) {
        if(__builtin_popcount(i) != N / 2) {    // 정학히 반으로 나눠지지 않은 경우 무시
            continue;
        }
        vector<int> morning, evening;

        // 스타트팀 링크팀을 벡터로 따로 분리
        for(int j = 1, bit = 1; j <= N; j++, bit <<= 1) {
            if(bit & i) morning.push_back(j);
            else evening.push_back(j);
        }   // end of for j

        res = min(res, get_score(morning, evening));

    }   // end of for i

    cout << res << "\n";
    return 0;
}