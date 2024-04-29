#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Pos {
    int r, c;
};

int N, M, d, p, res;
int a[20][20], visited[20][20];
int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {1, 1, 0, -1, -1, -1, 0, 1};
vector<Pos> nutrition;

void print() {
    cout << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << a[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
}

int range_check(int x) {
    if(x >= N) {
        return 0;
    } else if(x < 0) {
        return N - 1;
    }
    return x;
}

void move_nutrition() {
    // 영양제 표시한 위치 초기화
    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < nutrition.size(); i++) {
        int nr = nutrition[i].r;
        int nc = nutrition[i].c;

        // 한 칸씩 이동하면서 격자 체크
        for(int j = 0; j < p; j++) {
            // 이동
            nr += dr[d];
            nc += dc[d];

            // 격자 넘어갔는지 체크
            nr = range_check(nr);
            nc = range_check(nc);
        }   // end of for p

        // 영양제 위치 표시 for 새로운 영양제 만들때 현 위치 포함시키지 않기 위해
        visited[nr][nc] = 1;

        // 위치 갱신
        nutrition[i].r = nr;
        nutrition[i].c = nc;

    }   // end of for nutrition
}

void injection() {
    // 영양제 투입
    for(int i = 0; i < nutrition.size(); i++) {
        a[nutrition[i].r][nutrition[i].c]++;
    }
}

void diagonal() {
    for(int i = 0; i < nutrition.size(); i++) {
        int r = nutrition[i].r;
        int c = nutrition[i].c;

        // 대각 방향 확인
        for(int j = 0; j < 4; j++) {
            int nr = r + dr[j * 2 + 1];
            int nc = c + dc[j * 2 + 1];
            // 격자 벗어나는지 확인
            if(nr < 0 || nr >= N || nc < 0 || nr >= N) continue;
            // 대각에 높이 1 이상이 아니면 무시
            if(a[nr][nc] < 1) continue;

            a[r][c]++;
        }   // end of for diagonal
    }   // end of for nutrition
}

void create_nutrition() {
    nutrition.clear();

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            // 현재 투입된 영양제거나 높이가 2가 안되는 경우 무시
            if(a[i][j] < 2 || visited[i][j]) continue;

            a[i][j] -= 2;
            nutrition.push_back({i, j});
        }   // end of for j
    }   // end of for i
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
        }   // end of for j
    }   // end of for i

    // 좌측 하단에 네개 초기 영양제 벡터에 표시
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            nutrition.push_back({N - 1 - i, j});
        }
    }

    for(int i = 1; i <= M; i++) {
        cin >> d >> p;
        d--;
        move_nutrition();
        //print();
        injection();
        //print();
        diagonal();
        //print();
        create_nutrition();
    }   // end of for

    // 높이 총 합 계산
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            res += a[i][j];
        }
    }

    cout << res << '\n';

    return 0;
}