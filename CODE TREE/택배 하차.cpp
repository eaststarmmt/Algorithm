#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define INF 1e9

using namespace std;

struct Parcel {
    int startC, endC, startR, endR;
    bool isExist;
};

int a[54][54];
int N, M, K, H, W, C;
int isDown[104];
vector<int> output;
vector<Parcel> parcelList;

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

void eraseParcel(int num) {
    // 기존 영역 제거
    int startR = parcelList[num].startR;
    int endR = parcelList[num].endR;
    int startC = parcelList[num].startC;
    int endC = parcelList[num].endC;

    for(int r = startR; r <= endR; r++) {
        for (int c = startC; c <= endC; c++) {
            a[r][c] = 0;
        }   // end of for C
    }   // end of for R
}

// 택배 바닥으로 내리는 작업
void downParcel(int num) {
    int startC = parcelList[num].startC;
    int endC = parcelList[num].endC;
    int endR = parcelList[num].endR;
    int nr, nc;

    // 밑바닥에 다른 택배 있는지 확인
    for(nr = endR + 1; nr < N; nr++) {
        bool isMove = true;

        for(nc = startC; nc <= endC; nc++) {
            if(a[nr][nc]) {     // 0이 아니면 못내려감
                isMove = false;
                break;
            }
        }   // end of for nc
        if(!isMove) break;      // 이동 못하면 여기서 멈춤
    }   // end of for nr

    nr--;   // 마지막에 불필요하게 하나 증가해서 다시 줄여줌

    // 기존 영역 제거
    eraseParcel(num);

    // 새 영역에 값 갱신
    int startR = parcelList[num].startR + (nr - endR);
    endR = nr;
    for(int r = startR; r <= endR; r++) {
        for(int c = startC; c <= endC; c++) {
            a[r][c] = num;
        }   // end of for c
    }   // end of for r

    parcelList[num].startR = startR;
    parcelList[num].endR = endR;
}

void leftUnload() {
    int target = INF;

    for(int i = 1; i <= 100; i++) {
        if(!parcelList[i].isExist) continue;
        if(target != INF) break;    // 이미 타겟이 들어있으면 종료

        int startC = parcelList[i].startC;
        int startR = parcelList[i].startR;
        int endR = parcelList[i].endR;

        bool isUnload = true;

        for(int c = startC - 1; c >= 0; c--) {
            if(!isUnload) break;

            for(int r = startR; r <= endR; r++) {
                if(a[r][c]) {
                    isUnload = false;
                    break;
                }
            }   // end of for r
        }   // end of for c

        if(!isUnload) continue;     // 못옮기는 택배면 다음꺼 확인

        target = i;     // 여기까지 왔으면 됨
    }   // end of for i

    eraseParcel(target);    // 택배 제거
    parcelList[target].isExist = false;
    output.push_back(target);
}

void rightUnload() {
    int target = INF;

    for(int i = 1; i <= 100; i++) {
        if(!parcelList[i].isExist) continue;
        if(target != INF) break;    // 이미 타겟이 들어있으면 종료

        int endC = parcelList[i].endC;
        int startR = parcelList[i].startR;
        int endR = parcelList[i].endR;

        bool isUnload = true;

        for(int c = endC + 1; c < N; c++) {
            if(!isUnload) break;

            for(int r = startR; r <= endR; r++) {
                if(a[r][c]) {
                    isUnload = false;
                    break;
                }
            }   // end of for r
        }   // end of for c

        if(!isUnload) continue;     // 못옮기는 택배면 다음꺼 확인

        target = i;     // 여기까지 왔으면 됨
    }   // end of for i

    eraseParcel(target);    // 택배 제거
    parcelList[target].isExist = false;
    output.push_back(target);
}

void afterUnload() {
    memset(isDown, 0, sizeof(isDown));
    for(int r = N - 1; r >= 0; r--) {   // 밑에서부터 하나씩 아래로 내림
        for(int c = 0; c < N; c++) {
            int num = a[r][c];

            if(!num) continue;  // 빈칸이면 무시
            if(!parcelList[num].isExist) continue;  // 존재하지 않으면 무시
            if(isDown[num]) continue;   // 이미 내렸으면 무시

            downParcel(num);
            isDown[num] = 1;    // 바닥으로 내린 애들 표시
        }   // end of for c
    }   // end of for r
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    parcelList.resize(104);

    for(int i = 0; i < M; i++) {
        cin >> K >> H >> W >> C;
        C -= 1;
        parcelList[K] = {C, C + W - 1, 0, H - 1, true};
        downParcel(K);
    }   // end of for

    while(output.size() != M) {
        leftUnload();
        afterUnload();
        rightUnload();
        afterUnload();

    }   // end of for while

    for(int x : output) {
        cout << x << '\n';
    }   // end of for output
}

/*

input
30 20
98 2 10 12
15 6 1 1
45 9 5 2
49 3 8 8
34 8 2 21
40 7 7 23
79 8 5 16
5 7 7 7
6 4 6 25
94 4 6 19
26 5 3 2
35 5 2 29
8 14 10 5
86 11 13 16
60 4 1 1
88 7 3 2
38 1 1 1
32 1 9 16
30 2 8 18
7 1 5 10

output
7
6
15
30
26
32
38
35
60
40
45
34
8
79
88
86
5
94
49
98
 */