#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cstring>

using namespace std;

struct Leader {
    int r, c, food;
};
constexpr int MINT = 1;
constexpr int CHOCO = (1 << 1);
constexpr int MILK = (1 << 2);
constexpr int CHOCO_MILK = CHOCO | MILK;
constexpr int MINT_MILK = MINT | MILK;
constexpr int MINT_CHOCO = MINT | CHOCO;
constexpr int MINT_CHOCO_MILK = MINT | CHOCO | MILK;

map<char, int> mp = {
          {'T', 1}
        , {'C', 1<<1}
        , {'M', 1<<2}
};
int F[54][54];
int B[54][54], isSpread[54][54], group[54][54];
int N, T, cnt;
int dr[] = {-1, 1, 0, 0,};
int dc[] = {0, 0, -1, 1};
vector<Leader> leaderList, groupList;
int output[14];
vector<int> outputList = {MINT_CHOCO_MILK, MINT_CHOCO, MINT_MILK, CHOCO_MILK, MILK, CHOCO, MINT};

void print(int a[54][54]) {
    cout << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << a[i][j] << '\t';
        }
        cout << endl;
    }

    cout << endl;
}

void breakfast() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            B[i][j]++;
        }   // end of for j
    }   // end of for i
}
bool cmp(Leader l1, Leader l2) {
    int l1Cnt = __builtin_popcount(F[l1.r][l1.c]);
    int l2Cnt = __builtin_popcount(F[l2.r][l2.c]);

    if(l1Cnt == l2Cnt) {
        int b1 = B[l1.r][l1.c];
        int b2 = B[l2.r][l2.c];

        if(b1 == b2) {
            if(l1.r == l2.r) {
                return l1.c < l2.c;
            }
            return l1.r < l2.r;
        }
        return b1 > b2;
    }
    return l1Cnt < l2Cnt;
}

Leader compare(Leader l1, Leader l2) {
    int l1Cnt = __builtin_popcount(F[l1.r][l1.c]);
    int l2Cnt = __builtin_popcount(F[l2.r][l2.c]);

    if(l1Cnt < l2Cnt) return l1;
    else if (l1Cnt > l2Cnt) return l2;

    int b1 = B[l1.r][l1.c];
    int b2 = B[l2.r][l2.c];

    if(b1 < b2) return l2;
    else if(b1 > b2) return l1;

    if(l1.r < l2.r) return l1;
    else if(l1.r > l2.r) return l2;

    if(l1.c < l2.c) return l1;
    else if(l1.c > l2.c) return l2;
}

Leader dfs(int r, int c, Leader leader) {
    Leader cur = leader;
    int num = cur.food;
    group[r][c] = num;

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;    // 벗어나는지
        if(group[nr][nc] != -1) continue;   // 이미 방문한 곳인지
        if(num != F[nr][nc]) continue;  // 나랑 다른 그룹 가야 되는지

        Leader next = dfs(nr, nc, {nr, nc, F[nr][nc]});

        cur = compare(next, cur);
    }   // end of for

    groupList.push_back({r, c, F[r][c]});  // 대표자한테 줄 신앙심 뺄 사람 고르기 위함

    return cur;
}

void lunch() {
    memset(group, -1, sizeof(group));
    leaderList.clear();     // 리더들을 담을 리스트
    cnt = 0;
    for(int j= 0; j < N; j++) {
        for(int i = 0; i < N; i++) {
            if(group[i][j] != -1) continue;
            groupList.clear();
            Leader leader = dfs(i, j, {i, j, F[i][j]});
            B[leader.r][leader.c] += groupList.size();

            // 대표자에게 준 신앙심 제거
            for(Leader l : groupList) {
                B[l.r][l.c]--;
            }

            leaderList.push_back(leader);
        }   // end of for j
    }   // end of for i


}

void spread(Leader leader) {
    int r = leader.r;
    int c = leader.c;
    int f = F[r][c];
    int &b = B[r][c];
    int dir = b % 4;
    int x = b - 1;
    b = 1;
    int nr = r;
    int nc = c;

    while(x > 0) {
        nr += dr[dir];
        nc += dc[dir];

        if(nr < 0 || nr >= N || nc < 0 || nc >= N) break;

        int& nf = F[nr][nc];
        if(nf == f) continue;   // 음식 완전히 같은 경우

        int& nb = B[nr][nc];
        if (x > nb) {   // 완전 동화
            x -= nb + 1;
            nb++;
            nf = f;
        } else {
            nf = (nf | f);
            nb += x;
            x = 0;
        }

        isSpread[nr][nc] = 1;
    }   // end of while
}

void dinner() {
    sort(leaderList.begin(), leaderList.end(), cmp);
    memset(isSpread, 0, sizeof(isSpread));

    for(Leader leader: leaderList) {
        if(isSpread[leader.r][leader.c]) continue;  // 전파 받았으면 무시
        spread(leader);
//        print(B);
    }   // end of for leader
}

void answerPrint() {
    memset(output, 0, sizeof(output));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int f = F[i][j];    // 음식 번호를 인덱스 삼아서 저장
            output[f] += B[i][j];
        }
    }

    for(int x : outputList) {
        cout << output[x] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> T;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            F[i][j] = mp[s[j]];  // 해당 음식에 표시
        }   // end of for j
    }   // end of for i

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> B[i][j];
        }   // end of for j
    }   // end of for i

    for(int day = 1; day <= T; day++) {
        breakfast();
//        cout << day << "일차 breakfast()";
//        print(B);
        lunch();
//        cout << day << "일차 lunch()";
//        print(B);
        dinner();
//        cout << day << "일차 dinner()";
//        print(F);
        answerPrint();
    }   // end of day
}