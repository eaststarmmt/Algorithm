#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int C;

bool cmp(vector<int>& a, vector<int> b) {
    if(a[C] == b[C]) {
        return a[0] > b[0];
    }
    return a[C] < b[C];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    C = col - 1;    // 문제에서 인덱스 시작이 0이 아닌 1임
    // 정렬
    sort(data.begin(), data.end(), cmp);

    // 나누고 누적 xor
    for(int i = row_begin - 1; i <= row_end - 1; i++) {
        int mod = i + 1;    // 헷갈리지 않기 위해 나눌 인덱스 값 중간변수로 사용
        int sum = 0;    // 나머지 더한 값 저장할 변수
        // mod로 나눈 나머지 값 저장
        for(int j = 0; j < data[i].size(); j++) {
            sum += data[i][j] % mod;
        }
        answer ^= sum;  // xor 연산 특성상 0일때 어떤 값이 와도 그 값이 보장되므로 초깃값 신경 쓸 필요 없음
    }
    return answer;
}