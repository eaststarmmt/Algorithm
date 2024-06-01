#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define INF 1e9

using namespace std;

int N, M, res = INF;
int a[50][50], visited[50][50];
vector<pair<int, int>> hospital;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int get_max_visited() {
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(a[i][j]) continue;   // 바이러스 아니면 무시
            else if(!visited[i][j]) return -1;  // 바이러스인데 방문한 적 없으므로 제거 실패
            cnt = max(cnt, visited[i][j]);
        }
    }
    return !cnt ? 0 : cnt - 1;     // 병원 자체가 처음에 1로 시작해서 1 빼줘야 됨. 처음부터 바이러스가 없었으면 0
}

int bfs(vector<pair<int, int>> selected) {
    int cnt = -1;
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> Q;

    for(pair<int, int> p : selected) {  // 병원 위치 큐에 저장
        int r = p.first;
        int c = p.second;
        Q.push({r, c});
        visited[r][c] = 1;
    }   // end of for selected

    while(!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(visited[nr][nc]) continue;
            if(a[nr][nc] == 1) continue;     // 벽이면 무시. 병원은 통과는 가능해야 됨

            Q.push({nr, nc});
            visited[nr][nc] = visited[r][c] + 1;
        }   // end of for
    }   // end of while

    cnt = get_max_visited();    // 바이러스가 없으면 가장 오래 걸린 시간 가져오기
    return cnt;
}

void comb(vector<pair<int, int>> selected, int start) {
    if(selected.size() == M) {
        int cnt = bfs(selected);
        res = cnt == -1 ? res : min(cnt, res);  // -1이면 제거 실패 이므로 유지하고 아니면 최솟값
        return;
    }

    for(int i = start; i < hospital.size(); i++) {    // 조합으로 병원 선택
        selected.push_back(hospital[i]);
        comb(selected, i + 1);
        selected.pop_back();
    }   // end of for
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    queue<pair<int, int>> Q;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
            if(!a[i][j]) Q.push({i, j});
            else if(a[i][j] == 2) hospital.push_back({i, j});
        }   // end of for j
    }   // end of for i

    comb(vector<pair<int, int>>(), 0);

    if(res == INF) cout << -1 << '\n';
    else cout << res << '\n';

    return 0;
}