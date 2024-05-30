#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> tree, y_list;   // 펜윅트리와 y의 좌표를 저장할 벡터. x를 기준으로 정렬하기 때문에 y값을 저장.
vector<pair<int, int>> pos; // 좌표값 정렬을 위한 벡터
int x, y, N, T;

int find_index(vector<int>& v, int target) {
    int lo = 0;
    int hi = v.size() - 1;

    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(v[mid] == target) return mid + 1;
        else if(target < v[mid]) hi = mid - 1;
        else lo = mid + 1;
    }   // end of while
}

void update(int idx, int value) {
    while(idx < tree.size()) {
        tree[idx] += value;
        idx += (idx & -idx);
    }
    return;
}

int sum(int idx) {
    int res = 0;
    while(idx > 0) {
        res += tree[idx];
        idx -= idx & -idx;
    }   // end of while
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) {
        cin >> N;
        pos.clear();
        y_list.clear();
        tree.clear();
        tree.resize(N + 1);
        for(int i = 0; i < N; i++) {
            cin >> x >> y;
            pos.push_back({x, -y}); // x와 y 증감 방향을 맞추기 위해 부호 바꿈
            y_list.push_back(-y);   // 위와 같은 이유로 부호 바꿈. y를 좌표가 아닌 인덱스로 처리하여 좌표 압축
        }   // end of for input

        // 누적합 개념으로 처리하기 위해 정렬
        sort(pos.begin(), pos.end());
        sort(y_list.begin(), y_list.end());

        int idx = find_index(y_list, pos[0].second);
        update(idx, 1);
        long long res = 0;  // 만약 섬이 한개면 for문을 안들어가서 0이 나옴
        for(int i = 1; i < N; i++) {
            idx = find_index(y_list, pos[i].second);
            res += (long long) sum(idx);
            update(idx, 1); // 마지막은 개수 셀 필요 없음. 쌍을 구하는 거라서 앞에서 나온 누적합이면 충분함
        }

        cout << res << '\n';
    }   // end of while

    return 0;
}
