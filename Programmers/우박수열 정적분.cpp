#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<double> areas;    // 누적합 면적
vector<int> points;  // k 값 변화 과정. 인덱스가 x 좌표

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    points.push_back(k);
    areas.push_back(0);

    while(k != 1) {
        if(k & 1) k = k * 3 + 1;
        else k /= 2;
        points.push_back(k);
    }   // end of while

    for(int i = 1; i < points.size(); i++) {
        // x 좌표 기준 간격 1마다 넓이 저장
        double area = (double)(points[i] + points[i - 1]) / 2;
        areas.push_back(area + areas[i - 1]);
    }   // end of for

    for(vector<int> range : ranges) {
        int a = range[0];
        int b = range[1];
        if(b <= 0) b = points.size() - 1 + b;

        double res = b < a ? -1 : areas[b] - areas[a];

        answer.push_back(res);
    }

    return answer;
}