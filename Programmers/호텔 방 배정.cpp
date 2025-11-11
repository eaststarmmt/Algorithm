#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<long long, long long> visited;

long long findRoom(long long room) {
    if(!visited[room]) return room;     // 비었으면 여기에 넣으면 됨
    return visited[room] = findRoom(visited[room]);     // 다음번에는 한번에 찾기 위해 재귀로 부모 찾아서 넣어줌
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for(long long room : room_number) {
        if(!visited[room]) {
            answer.push_back(room);
            visited[room] = findRoom(room + 1); // 하나 위를 불렀을때 들어갈 방
            continue;
        }

        long long nextRoom = findRoom(room);
        answer.push_back(nextRoom);
        visited[nextRoom] = findRoom(nextRoom + 1);     // 다음번에 오면 지금 넣은거 바로 위 값의 부모까지 한번에 가기 위함. 만약 비었다면 빈 방 바로 연결 됨
    }
    return answer;
}