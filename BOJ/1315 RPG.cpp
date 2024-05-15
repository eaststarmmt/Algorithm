#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Quest {
    int r, c, p;    // 각 퀘스트 별 str, int, point
};

int N;
int dp[1004][1004];     // idx 는 각각 str, int 를 의미. 안에 값은 가능한 퀘스트 개수
bool visited[54];    // 퀘스트 깼는지 여부 확인용
vector<Quest> quest;

int go(int STR, int INT) {
    int &ret = dp[STR][INT];
    if(ret != -1) return ret;   // STR, INT 에 대한 값이 저장되어 있다면 메모이제이션 활용

    ret = 0;
    int point = 0;  // 현재 능력치에서 얻을 수 있는 포인트를 더할 변수
    vector<int> v;  // 처음 완료한 퀘스트 목록

    for(int i = 0; i < N; i++) {
        if(quest[i].r > STR && quest[i].c > INT) continue;  // str, int 둘 다 충족되지 못한 경우

        ret++;  // 현재 능력치에서 완료 가능한 퀘스트 카운팅

        if(visited[i])  continue;   // 퀘스트 완료 기록 있으면 무시

        visited[i] = true;  // 퀘스트 완료 표시
        point += quest[i].p;
        v.push_back(i);     // 현재 능력치에서 처음 방문한 퀘스트 인덱스 저장
    }   // end of for

    for(int i = 0; i <= point; i++) {
        // 1000을 넘길 수 없음
        int next_str = min(1000, STR + i);
        int next_int = min(1000, INT + point - i);

        ret = max(ret, go(next_str, next_int));
    }   // end of for

    // 다음 재귀를 위해 현 위치에서 방문 표시한 인덱스 원복
    for(int x : v) {
        visited[x] = false;
    }   // end of for

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int r, c, p;
        cin >> r >> c >> p;
        quest.push_back({r, c, p});
    }   // end of for

    memset(dp, -1, sizeof(dp));
    cout << go(1, 1) << '\n';
    return 0;
}