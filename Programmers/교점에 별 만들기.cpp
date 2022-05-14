#include <string>
#include <vector>
#include <set>
using namespace std;
set<pair<long long, long long>> cross;
long long minR, minC, maxR, maxC;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    minR = minC = 1e15;
    maxR = maxC = -1e15;
    for(int i = 0; i < line.size() - 1; i++) {
        long long A = line[i][0];
        long long B = line[i][1];
        long long E = line[i][2];
        for(int j = i + 1; j < line.size(); j++) {  // 선 두개 선택
            long long C = line[j][0];
            long long D = line[j][1];
            long long F = line[j][2];
            long long ADBC = A * D - B * C;
            long long BFED = B * F - E * D;
            long long ECAF = E * C - A * F;
            if(ADBC == 0) continue;     // 분모 0 되는 경우
            if((BFED % ADBC) != 0 || (ECAF % ADBC) != 0) continue;  // 교점이 정수가 아닌 경우
            cross.insert({ECAF / ADBC, BFED / ADBC});
            // 맵 크기 측정
            maxR = ECAF / ADBC > maxR ? ECAF / ADBC : maxR;
            minR = ECAF / ADBC < minR ? ECAF / ADBC : minR;
            maxC = BFED / ADBC > maxC ? BFED / ADBC : maxC;
            minC = BFED / ADBC < minC ? BFED / ADBC : minC;
        }   // end of for j
    }   // end of for i
    
    // 출력할 map '.'으로 초기화
    for(int i = 0; i <= maxR - minR; i++) {     // 0부터 시작했는데 max도 찍혀야 되기 때문에 +1
        string s;
        for(int j = 0; j <= maxC - minC; j++) {
            s.append(".");
        }   // end of for j
        answer.push_back(s);
    }   // end of for i
    
    for(auto i : cross) {
        answer[maxR - i.first][i.second - minC] = '*';  // [y][x] 형태. y좌표는 위로 갈수록 더 큰 수이므로 max값에서 빼줘야됨
    }
    return answer;
}