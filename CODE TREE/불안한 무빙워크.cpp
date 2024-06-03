#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Info {       // 벨트에 저장할 값들. 안정도, 사람 있는지 여부
    int safe, human;
};
int N, K, safe, res;
vector<Info> velt;

void safety_counting(int x) {
    if(x <= 0) K--;     // 안정성이 0이하면 카운팅
}

void remove_human() {
    if(velt[N - 1].human) { // N번째 위치에 사람이 있다면 내리고 카운팅
        velt[N - 1].human = 0;
    }
}

void move_belt() {
    // 벨트 회전
    rotate(velt.begin(), velt.begin() + 2 * N - 1, velt.end());
    remove_human();     // N번째 사람 있으면 내리기
}

void move_human() {
    // 사람은 절반만 사용할 수 있기 때문에 인덱스가 큰 벨트에 있는 사람이 무조건 먼저 올라온 사람
    for(int i = N - 2; i >= 0; i--) {
        if(velt[i + 1].safe == 0) continue; // 다음 위치 안정성 0이면 무시
        if(velt[i + 1].human) continue;     // 다른 사람 있으면 무시
        if(!velt[i].human) continue;    // 현 위치에 사람 없으면 무시

        // 사람 이동
        velt[i + 1].human = 1;
        velt[i].human = 0;
        velt[i + 1].safe--;    // 안정성 1 감소
        safety_counting(velt[i + 1].safe);
    }   // end of for
    // 이동으로 인해 N번째 사람 왔으면 내리기
    remove_human();
}

void add_human() {
    if(velt[0].human) return;   // 첫번째 사람 있으면 종료
    if(!velt[0].safe) return;   // 첫번째 안정성 0이면 종료

    velt[0].human = 1;
    velt[0].safe--;
    safety_counting(velt[0].safe);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for(int i = 0; i < 2 * N; i++) {
        cin >> safe;
        velt.push_back({safe, 0});
    }   // end of for

    while(K > 0) {  // K가 음수가 될 수도 있기 때문
        res++;
        // 벨트 회전
        move_belt();
        move_human();
        add_human();
    }   // end of while

    cout << res << '\n';
}