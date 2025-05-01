#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#define MAX 100001
#define MAX_IDX (MAX * 2 + 2)
using namespace std;

int N, M, T;
int tree[MAX_IDX];
map<int, int> mp;   // 해당 번호의 책의 인덱스를 저장하는 맵

void update(int idx, int value) {
    int i = idx;
    while(i < MAX_IDX) {
        tree[i] += value;
        i += (i & -i);
    }   // end of while
}

int sum(int idx) {
    int i = idx;
    int res = 0;
    while(i > 0) {
        res += tree[i];
        i -= (i & -i);
    }   // end of while
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for(int t = 1; t <= T; t++) {
        cin >> N >> M;
        memset(tree, 0, sizeof(tree));
        int update_idx = MAX;   // 위로 쌓으면서 아래에 있는 개수를 구해야 하는데 이 과정을 위해 10만 이후부터 인덱스를 사용하고 앞에다 쌓기 위함
        mp.clear();

        // 가지고 있는 영화 수 만큼 트리에 넣기
        for(int i = 1; i <= N; i++) {
            int idx = update_idx + i;
            mp[i] = idx;
            update(idx, 1);  // 펜윅트리에 1씩 미리 초기화. 1 ~ N까지 1이 들어가 있게 됨
        }   // end of for N

        for(int i = 0; i < M; i++) {
            int x;
            cin >> x;
            int idx = mp[x];    // x가 현재 있는 위치를 가져옴
            cout << sum(idx) - 1 << ' ';
            update(idx, -1);    // 지금 본 책은 위로 쌓이기 때문에 빼줘야 됨
            update(--update_idx, 1);    // update_idx에서 1을 빼줌으로 가장 위에 위치를 표시
            mp[x] = update_idx;
        }   // end of for M

        cout << '\n';
    }   // end of T
}