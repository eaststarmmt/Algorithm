#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int a[14][14];  // 현재 지도에 있는 양분
int input[14][14];  // 매 싸이클 이후 추가되는 양분
vector<int> age[14][14];   // 바이러스 나이
int N, M, K;
int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void print() {
    cout << endl;
    for(int i = 0; i < 14; i++) {
        for(int j = 0; j < 14; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

void add_age(int r, int c) {
    vector<int> v = age[r][c];     // r,c에 들어있는 바이러스들
    vector<int> temp;
    sort(v.begin(), v.end());   // 어린 바이러스부터 오름차순

    int die = 0;    // 바이러스 죽어서 생길 양분

    for(int i = 0; i < v.size(); i++) {
        int x = v[i];
        if(x <= a[r][c]) {          // 양분이 충분한 경우
            a[r][c] -= x;           // 나이만큼 양분 감소
            temp.push_back(++x);    // 한 살 증가한거 새로운 벡터에 저장
            continue;
        }
        // 양분이 부족한 경우
        die += x / 2;   // 죽은 바이러스는 나이의 절반이 양분이 됨
    }   // end of for

    age[r][c] = temp;   // 살아남은 바이러스들 나이 저장
    a[r][c] += die;     // 바이러스 죽어서 생긴 양분 저장
}

void breed_map(int r, int c) {
    for(int i = 0; i < 8; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;    // 범위 벗어나면 무시
        age[nr][nc].push_back(1);   // 새로운 바이러스 생성
    }   // end of for
}

void breed_check(int r, int c) {
    vector<int> v = age[r][c];
    for(int x : v) {
        if(x % 5) continue;     // 5의 배수만 번식
        breed_map(r, c);
    }

}

void growth() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(age[i][j].empty()) continue; // 바이러스 없으면 무시
            add_age(i, j);
        }   // end of for j
    }   // end of for i
}

void breed() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(age[i][j].empty()) continue;
            breed_check(i, j);
        }
    }
}

void add_nourish() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            a[i][j] += input[i][j];
        }
    }
}

int calc() {
    int res = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            res += age[i][j].size();
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> input[i][j];
        }   // end of for j
    }   // end of for i

    for(int i = 0; i < M; i++) {
        int r, c, x;
        cin >> r >> c >> x;
        age[--r][--c].push_back(x); // 해당 위치에 나이 저장
    }

    fill(&a[0][0], &a[0][0] + 14 * 14, 5);  // 처음 양분은 5

    int cycle = K;
    while(cycle--) {
        growth();
        breed();
        add_nourish();
    }
    cout << calc() << '\n';
}