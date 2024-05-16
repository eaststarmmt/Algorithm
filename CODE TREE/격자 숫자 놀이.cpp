#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>

using namespace std;

int a[104][104], temp[104][104];
int R = 3, C = 3, K, target_r, target_c, res = -1;
map<int, int> m;   // 카운팅 하기 위한 맵. 숫자, 빈도수 꼴로 저장

void print(int a[104][104]) {
    cout << endl;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

vector<pair<int, int>> freq_sort(vector<pair<int, int>> pos) {
    m.clear();  // 맵 초기화
    // 빈도수 카운팅
    for(pair<int, int> p : pos) {
        int r = p.first;
        int c = p.second;
        m[a[r][c]]++;   // a[r][c]에 들어있는 값 카운팅
    }   // end of for pos

    vector<pair<int, int>> v(m.begin(), m.end());   // 체크한 빈도수 벡터로 이동
    sort(v.begin(), v.end(), cmp);

    return v;   // 정렬한 벡터 리턴
}

int row() {     // 행 연산 하면 열의 크기가 변함. 맥스 크기 값 갱신하기 위해 리턴
    int max_c = 0;
    for(int i = 0; i < R; i++) {
        vector<pair<int, int>> v;
        for(int j = 0; j < C; j++) {
            if(!a[i][j]) continue;
            v.push_back({i, j});
        }   // end of for j
        vector<pair<int, int>> sorted_v = freq_sort(v); // 빈도수 오름차순 정렬. 값, 빈도수 형태로 저장되어 있음
        int size = min((int)sorted_v.size(), 50);   // 크기 100개 넘으면 뒤에 값 버려야 됨.
        max_c = max(max_c, size * 2);   // 지금까지 나온 열 길이 중 가장 큰 값 저장
        for(int j = 0; j < size; j++) {     // 정렬된 값 채우기
            temp[i][j * 2] = sorted_v[j].first;
            temp[i][j * 2 + 1] = sorted_v[j].second;
        }   // end of for j
    }   // end of for i

    return max_c;
}

int col() {     // 열 연산 하면 행의 크기가 변함. 맥스 크기 값 갱신하기 위해 리턴
    int max_r = 0;
    for(int j = 0; j < C; j++) {    // 이거 괜히 헷갈리면 안되니까 j로 시작. 실수하면 참사남
        vector<pair<int, int>> v;
        for(int i = 0; i < R; i++) {
            if(!a[i][j]) continue;
            v.push_back({i, j});
        }   // end of for R

        vector<pair<int, int>> sorted_v = freq_sort(v); // 빈도수 오름차순 정렬. 값, 빈도수 형태로 저장되어 있음
        int size = min((int)sorted_v.size(), 50);   // 크기 100개 넘으면 뒤에 값 버려야 됨.
        max_r = max(max_r, size * 2);   // 지금까지 나온 행 길이 중 가장 큰 값 저장
        for(int i = 0; i < size; i++) {     // 정렬된 값 채우기
            temp[i * 2][j] = sorted_v[i].first;
            temp[i * 2 + 1][j] = sorted_v[i].second;
        }   // end of for j
    }   // end of for C

    return max_r;
}

void go() {
    memset(temp, 0, sizeof(temp));  // 빈칸 0으로 채우는 작업을 위해 초기화
    if(R >= C) C = max(row(), C);   // 정렬하고 다시 넣는 과정에서 열의 최대 길이가 바뀔수 있음
    else R = max(col(), R);
    memcpy(a, temp, sizeof(temp));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> target_r >> target_c >> K;
    target_r--;
    target_c--;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    int cnt = -1;

    while(++cnt < 100) {
        if(a[target_r][target_c] == K) {
            res = cnt;
            break;
        }
        go();
    }   // end of while
    cout << res << '\n';
    return 0;
}