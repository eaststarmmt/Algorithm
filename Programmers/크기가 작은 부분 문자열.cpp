#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int size = p.size();
    long long target = stol(p);

    for(int i = 0; i < t.size() - size + 1; i++) {
        long long x = stol(t.substr(i, size));
        if(x <= target) answer++;
        
    }   // end of for
    
    return answer;
}