#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Pos {
    int r, c, like, empty;  // 해당 위치의 우선순위를 결정하는 요소들
};

int a[24][24];
int N, res;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

vector<int> like_list[404];
vector<int> student_list;   // 입력받는 학생 순서 기록
vector<Pos> pos_list;

bool cmp(Pos a, Pos b) {
    if(a.like == b.like) {
        if(a.empty == b.empty) {
            if(a.r == b.r) {
                return a.c < b.c;
            }
            return a.r < b.r;
        }
        return a.empty > b.empty;
    }
    return a.like > b.like;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N * N; i++) {
        int x;
        cin >> x;
        student_list.push_back(x);
        // 좋아하는 학생 배열
        for(int j = 0; j < 4; j++) {
            int y;
            cin >> y;
            like_list[x].push_back(y);
        }   // end of for j
    }   // end of for i

    // 학생 별로 빈 칸 모두 확인해서 칸의 우선순위를 이용하여 배치
    for(int id : student_list) {
        pos_list.clear();   // 학생별로 모든 위치를 보는 것이기 때문에 학생이 바뀌면 벡터를 비워줘야 됨
        for(int r = 1; r <= N; r++) {
            for(int c = 1; c <= N; c++) {
                if(a[r][c] != 0) continue;  // 이미 다른 학생 있으면 이 위치는 못들어감
                int like = 0;   // 현 위치에서 주변에 좋아하는 사람들 수 카운팅 할 변수
                int empty = 0; // 주변에 빈 칸 개수 셀 변수
                for(int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr < 1 || nr > N || nc < 1 || nc > N) continue;

                    // 좋아하는 사람 몇명인지 카운팅
                    for(int l : like_list[id]) {
                        if(l == a[nr][nc]) {
                            like++;
                            break;
                        }
                    }   // end of for like

                    // 주변에 빈 칸 개수 카운팅
                    if(a[nr][nc] == 0) empty++;
                }   // end of for 사방 탐색

                pos_list.push_back({r, c, like, empty});    // 자리에 대한 정보 저장
            }   // end of for c
        }   // end of for r

        // 우선순위 기준으로 정렬한 뒤 제일 높은 우선순위에 학생 저장
        sort(pos_list.begin(), pos_list.end(), cmp);
        a[pos_list[0].r][pos_list[0].c] = id;

    }   // end of for student

    // 점수 계산
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            int id = a[r][c];   // 해당 위치에 있는 학생
            int like = 0;
            // 사방 확인
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                for(int l : like_list[id]) {
                    if(l == a[nr][nc]) {
                        like++;
                        break;
                    }
                }   // end of for like

            }   // end of for 사방
            res += !like ? 0 : pow(10, like - 1);
        }   // end of for c
    }   // end of for r

    cout << res << '\n';

    return 0;
}