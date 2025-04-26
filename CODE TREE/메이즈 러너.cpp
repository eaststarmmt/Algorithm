#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int M, res, out_r, out_c, K, N;
int a[14][14], b[14][14], temp[14][14], temp2[14][14];
vector<pair<int, int>> parti_list;  // 참가자
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void print(int arr[][14]) {
    cout << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int get_dis(int r, int c) {
    return abs(r - out_r) + abs(c - out_c);
}

int get_dir(pair<int, int> p) {
    int dir = -1;   // 이동 불가능하면 -1
    int r = p.first;
    int c = p.second;

    int dis = get_dis(r, c);
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if(a[nr][nc] > 0) continue;

        int ndis = get_dis(nr, nc);
        if(ndis < dis) {    // 출구보다 가까운 경우
            dir = i;
            break;
        }
    }   // end of for

    return dir;
}

int move() {
    int cnt = 0;    // 참가자 이동 횟수
    priority_queue<int> pq; // 탈출한 사람 표시할 우선순위 큐. 내림차순 정렬

    for(int i = 0; i < parti_list.size(); i++) {
        int dir = get_dir(parti_list[i]);
        if(dir < 0) continue;

        cnt++;   // 이동 횟수 카운팅
        // 좌표 이동
        b[parti_list[i].first][parti_list[i].second]--;

        parti_list[i].first += dr[dir];
        parti_list[i].second += dc[dir];

        // 탈출 한 경우
        if(parti_list[i].first == out_r && parti_list[i].second == out_c) {
            pq.push(i);
            continue;
        }

        // 탈출하지 못한 경우만 새로 옮겨진 위치에 표시함
        b[parti_list[i].first][parti_list[i].second]++;

    }   // end of for parti

    // 탈출한 사람 제거
    while(!pq.empty()) {
        int x = pq.top();
        pq.pop();

        pair p = parti_list[x];
        // 리스트 제거
        parti_list.erase(parti_list.begin() + x);
    }   // end of while

    return cnt;
}

bool square_check(int r, int c, int size) {
    bool parti_check = false;
    bool out_check = false;

    for(int i = r; i <= r + size; i++) {
        for(int j = c; j <= c + size; j++) {
            if(b[i][j] > 0) parti_check = true;    // 참가자 포함 체크
            if(i == out_r && j == out_c) out_check = true;      // 출구 포함 체크
        }
    }

    return parti_check && out_check;
}

int get_size(int& start_r, int& start_c) {
    start_r = start_c = 0;
    int size = 0;

    for(size = 1; size < N; size++) {
        for(int r = 0; r < N - size; r++) {
            for(int c = 0; c < N - size; c++) {
                if(square_check(r, c, size)) {
                    start_r = r;
                    start_c = c;
                    return size;
                }
            }   // end of for c
        }   // end of for r
    }   // end of for size

    return size;
}

void set_rotate(int r, int c, int size, int arr[14][14]) {
    memset(temp, 0, sizeof(temp));
    memset(temp2, 0, sizeof(temp2));

    // 회전 영역 복사
    for(int i = 0; i <= size; i++) {
        for(int j = 0; j <= size; j++) {
            temp[i][j] = arr[i + r][j + c];
        }   // end of for j
    }   // end of for i

    // 회전하여 temp2에 저장
    for(int i = 0; i <= size; i++) {
        for(int j = 0; j <= size; j++) {
            temp2[i][j] = temp[size - j][i];
        }
    }   // end of for temp2

    // 원래 배열에 회전한 값 저장
    for(int i = 0; i <= size; i++) {
        for(int j = 0; j <= size; j++) {
            arr[i + r][j + c] = temp2[i][j];
        }
    }   // end of for arr
}

void damage_wall(int r, int c, int size) {  // 벽 회전마다 1씩 내구도 깎임
    for(int i = r; i <= r + size; i++) {
        for(int j = c; j <= c + size; j++) {
            if(a[i][j] == -1) continue;
            a[i][j] = max(a[i][j] - 1 , 0);
        }
    }
}

void rotate() {
    int start_r, start_c;
    int size = get_size(start_r, start_c);

    damage_wall(start_r, start_c, size);

    set_rotate(start_r, start_c, size, a);
    set_rotate(start_r, start_c, size, b);
    // 회전 영역 복사
}

void find_out() {   // 지도 정보 새로 갱신
    parti_list.clear();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(a[i][j] == -1) { // 출구 찾으면 출구 위치 갱신
                out_r = i;
                out_c = j;
            }
            // 해당 위치에 있는 참가자 수 만큼 push
            for(int x = 0; x < b[i][j]; x++) {
                parti_list.push_back({i, j});
            }   // end of for push
        }   // end of for j
    }   // end of for i
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
        }   // end of for j
    }   // end of for i

    for(int i = 0; i < M; i++) {
        int r, c;
        cin >> r >> c;
        parti_list.push_back({--r, --c});
        b[r][c]++;
    }   // end of for

    cin >> out_r >> out_c;
    out_r--; out_c--;
    a[out_r][out_c] = -1;   // 출구 따로 표시
    // 입력 끝

    while(K--) {
        res += move();
        if(parti_list.empty()) break;
        rotate();
        find_out();
    }   // end of while

    cout << res << '\n';
    cout << out_r + 1 << ' ' << out_c + 1 << '\n';

    return 0;
}