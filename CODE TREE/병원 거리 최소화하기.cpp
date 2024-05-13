#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

struct Pos {
    int r, c;
};

int a[54][54];
int N, M, res = INF;
vector<Pos> human, hospital;

int get_dis(vector<Pos>& selected) {
    int sum = 0;

    for(int i = 0; i < human.size(); i++) {
        int dis = INF;
        // 사람별로 가장 가까운 병원 거리 계산
        for(int j = 0; j < selected.size(); j++) {
            dis = min(dis, abs(human[i].r - selected[j].r) + abs(human[i].c - selected[j].c));
        }   // end of for dis
        sum += dis;
    }   // end of for

    return sum;
}

void go(vector<Pos> selected, int start) {
    if(selected.size() == M) {
        res = min(res, get_dis(selected));
        return;
    }   // end of if

    for(int i = start; i < hospital.size(); i++) {
        selected.push_back(hospital[i]);
        go(selected, i + 1);
        selected.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) human.push_back({i, j});   // 인간 위치 표시
            else if(a[i][j] == 2) hospital.push_back({i, j});   // 사람 위치 표시
        }   // end of for j
    }   // end of for i

    go(vector<Pos>(), 0);

    cout << res << '\n';
    return 0;
}