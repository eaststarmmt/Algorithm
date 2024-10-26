#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int get_level(int x) {    // 로그를 이용하여 레벨 구하기. 인자로 길이값을 받음
    return (int)(log(x) / log(2));
}

string long_to_binary(long long x) {    // 2진수로 변경. 거꾸로 되어 있는데 중요하지 않아서 놔둠
    string s = "0";     // 0번 인덱스를 채우고 시작하기 위함
    while(x) {
        s += to_string(x % 2);
        x /= 2;
    }   // end of while

    long long len = pow(2, get_level(s.size() - 1) + 1) - 1;    // 길이에 인덱스 0이 포함되어 있으므로 1을 빼서 매개변수로 보내야 됨
    int size = s.size() - 1;    // 0에대한 인덱스가 포함되어 있으므로

    for(int i = 0; i < len - size; i++) {   // 포화 이진트리 형태로 만들기 위함.
        s += '0';
    }   // end of for

    return s;
}

int dfs(int x, string& num, int level) {
    if(x % 2) return true;     // 리프노드가 탈출조건. 리프노드는 인덱스가 홀수

    int pow = 1 << (level - 1);
    int left = x - pow; // left = root - 2^(level-1)
    int right = x + pow; // right = root + 2^(level-1)

    // 왼쪽 자식 오른쪽 자식 재귀로 결과 값 가져오기
    int left_res = dfs(left, num, level - 1);
    int right_res = dfs(right, num, level - 1);

    if(!left_res || !right_res) return 0;   // 둘 중 하나라도 false면 0 리턴

    if(num[x] == '0') {
        if(num[left] != '0' || num[right] != '0') return 0; // root가 0인데 자식 둘 중 하나라도 더미노드가 아니면 안됨
    }
    return 1;      // 여기까지 무사히 왔으면 가능
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for(long long number : numbers) {
        string binary = long_to_binary(number);     // 2진수 값 가져오기

        int root = binary.size() / 2;   // root의 인덱스
        int res = dfs(root, binary, get_level(binary.size()) - 1);    // 가능 여부 체크
        answer.push_back(res);
    }
    return answer;
}
