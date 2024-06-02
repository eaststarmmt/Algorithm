#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, L, res;
int a[104][104];

bool check(vector<int> v) {
    int l = 0;  // x에 해당하는 높이의 시작 인덱스 저장
    for(int i = 1; i < v.size(); i++) {
        if(v[i] == v[i - 1]) continue;  // 길이 같으면 확인 할 이유가 없음
        else if(abs(v[i] - v[i - 1]) > 1) return false;    // 길이 차이 2 이상 나면 불가능
        else if(i - l < L && v[i] > v[i - 1]) return false;   // 길이가 L 이하인데 높아지면 불가능
        else if(i - l < L * 2 && l != 0 && v[l - 1] > v[i - 1] && v[i] > v[i - 1]) return false;   // 웅덩이 형태인데 2개 길이 안나오면 불가능
        l = i;
    }   // end of for

    if(v[v.size() - 1] > v[l] && v.size() - 1 < L) return false;    // 높아졌는데 길이가 L이 아니면 불가능
    return true;    // 여기까지 무사히 왔으면 뒤집어서 다시 화긴
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
        }   // end of for j
    }   // end of for i

    // 행 확인
    for(int r = 0; r < N; r++) {
        vector<int> v;   // 벡터로 값 넘겨서 편하게 확인하기 위함
        for(int c = 0; c < N; c++) {
            v.push_back(a[r][c]);
        }   // end of for c
        bool is_possible = check(v);
        if(!is_possible) continue;  // 안됐으면 무시
        reverse(v.begin(), v.end());
        if(check(v)) res++;
    }   // end of for r

    // 열 확인
    for(int c = 0; c < N; c++) {
        vector<int> v;   // 벡터로 값 넘겨서 편하게 확인하기 위함
        for(int r = 0; r < N; r++) {
            v.push_back(a[r][c]);
        }
        bool is_possible = check(v);
        if(!is_possible) continue;  // 안됐으면 무시
        reverse(v.begin(), v.end());
        if(check(v)) res++;
    }

    cout << res << '\n';
}