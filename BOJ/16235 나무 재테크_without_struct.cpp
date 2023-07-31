#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, K, x, y, z, res, A[14][14], land[14][14];
vector<int> tree[14][14];
int dr[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dc[] = {0, 1, 0, -1, -1, 1, -1, 1};

void spring_summer() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(tree[i][j].empty()) continue;

            vector<int> temp;   // 살릴 나무를 저장할 임시 벡터
            sort(tree[i][j].begin(), tree[i][j].end()); // 오름차순 정렬하여 어린 나무부터 양분 먹이기
            int die = 0;
            for(int age: tree[i][j]) {
                if(age > land[i][j]) {    // 나무가 죽는 경우
                    die += age / 2;   // 나이 / 2 저장. 바로 추가하면 다음 나무가 죽어야 되는데 살아버림
                    continue;
                }
                land[i][j] -= age;    // 나이 만큼 양분 먹음
                temp.push_back(age + 1);    // 한살 먹은 채로 임시 벡터에 저장
            }   // end of for tree

            tree[i][j] = temp;  // 살아있는 나무들 저장
            land[i][j] += die;  // 나무 죽어서 생긴 양분 저장
        }   // end of for j
    }   // end of for i
}

void fall() {
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            for(int age: tree[r][c]) {
                if(age % 5 != 0) continue;  // 5의 배수 아니면 번식 안함
                for(int i = 0; i < 8; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;    // 지도 범위 체크
                    tree[nr][nc].push_back(1);
                }
            }   // end of for tree
        }   // end of for j
    }   // end of for i
}

void winter() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            land[i][j] += A[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
        }   // end of for j
    }   // end of for i

    // 땅의 초기 양분은 5
    fill(&land[0][0], &land[0][0] + 14 * 14, 5);

    for(int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        tree[--x][--y].push_back(z);    // 0, 0부터 시작하기 위해 좌표값 하나씩 빼줌
    }   // end of for tree

    while(K--) {
        spring_summer();
        fall();
        winter();
    }   // end of while K

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            res += tree[i][j].size();
        }
    }

    cout << res << "\n";
    return 0;
}
