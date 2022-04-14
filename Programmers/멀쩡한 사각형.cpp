using namespace std;
// 모든 사각형 - (가로 + 세로 - 최대공약수)
long long solution(int w, int h) {
	long long answer = (long long)w * h - (w + h);
	while (h != 0) { // 유클리드 호제
		int d = w % h;
		w = h;
		h = d;
	}
	answer += w;
	return answer;
}