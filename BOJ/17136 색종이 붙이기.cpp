#include<iostream>
#include<algorithm>
#include<map>
#define INF 1e9
using namespace std;

int a[14][14], res = INF;
map<int, int> m;    // 종이크기, 사용한 개수

bool check(int r, int c, int size) {    // 확인하려는 사이즈 색종이 덮어지는지 확인하는 함수
    if(r + size > 10 || c + size > 10) return false;  // 범위 벗어나면 불가능
    for(int i = r; i < r + size; i++) {
        for(int j = c; j < c + size; j++) {
            if(a[i][j] == 0) return false;  // 0이 하나라도 있으면 색종이 못 덮음
        }   // end of for j
    }   // end of for i
    return true;
}

void draw(int r, int c, int size, int val) {
    for(int i = r; i < r + size; i++) {
        for(int j = c; j < c + size; j++) {
            a[i][j] = val;
        }   // end of for j
    }   // end of for i
}

void dfs(int r, int c, int cnt) {
    if(cnt >= res) return;  // 백트래킹. 지금까지 최솟값 보다 많으면 할 필요 없음
    if(r == 10) {   // 끝까지 다 했으면 종료
        res = min(res, cnt);    // 최솟값 갱신
        return;
    }
    if(c == 10) {   // 세로 끝까지 다 간 경우
        dfs(r + 1, 0, cnt);
        return;
    }

    if(a[r][c] == 0) {
        dfs(r, c + 1, cnt);
        return;
    }

    for(int size = 5; size >= 1; size--) {
        if(m[size] == 5) continue;  // 해당 사이즈 색종이 5개 다 썼으면 다음 사이즈 체크
        if(check(r, c, size)) {
            m[size]++;
            draw(r, c, size, 0);    // 한번 색종이를 덮은 곳은 다음번에 카운팅 되지 않도록 0처리
            dfs(r, c + size, cnt + 1);  // 카운팅 하고 다음 위치 확인
            draw(r, c, size, 1);    // 색종이 체크 해제하기 위해 원복
            m[size]--;  // 종이 사이즈 카운팅 한거 원복
        }
    }   // end of for size
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> a[i][j];
        }   // end of for j
    }   // end of for i

    dfs(0, 0, 0);
    cout << (res == INF ? -1 : res) << "\n";
}