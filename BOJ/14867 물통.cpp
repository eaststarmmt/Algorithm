#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

int a, b, c, d;
queue<pair<int, int>> Q;
map<pair<int, int>, int> m;

void enqueue(int x, int y, int cnt) {
    if(m[{x, y}]) return;   // visited 체크. 방문한 적 있으면 무시
    Q.push({x, y});
    m[{x, y}] = cnt + 1; // 지금까지 온 경로 + 1
}

int bfs() {
    Q.push({0, 0});
    m[{0, 0}] = 1;

    while(!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        // 가능한 경우의 수 다 넣기
        enqueue(a, y, m[{x, y}]);
        enqueue(x, b, m[{x, y}]);
        enqueue(0, y, m[{x, y}]);
        enqueue(x, 0, m[{x, y}]);
        enqueue(min(a, x + y), max(x + y - a, 0), m[{x, y}]);
        enqueue(max(0, x + y - b), min(b, x + y), m[{x, y}]);
    }   // end of while

    if(m[{c, d}]) return m[{c, d}] - 1;
    else return -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c >> d;

    cout << bfs() << "\n";

}