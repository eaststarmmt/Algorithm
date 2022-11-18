#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
int dp[1001][2001];
int solution(vector<int> elements) {
    int answer = 0;
    int N = elements.size();
    set<int> set;
    for(int i = 1; i <= N; i++) {
        dp[i][i] = elements[i - 1];
        set.insert(dp[i][i]);
    }   // end of for

    for(int from = 1; from <= N; from++) {
        for(int to = from + 1; to < from + N; to++) {
            int dest = (to % N);
            if(dest == 0) {
                dest = N - 1;
            } else {
                dest--;
            }
        
            dp[from][to] = dp[from][to - 1] + elements[dest];
            set.insert(dp[from][to]);
        }   // end of for to
    }   // end of for from
    
    answer = set.size();
    return answer;
}