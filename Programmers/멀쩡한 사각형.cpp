using namespace std;
// ��� �簢�� - (���� + ���� - �ִ�����)
long long solution(int w, int h) {
	long long answer = (long long)w * h - (w + h);
	while (h != 0) { // ��Ŭ���� ȣ��
		int d = w % h;
		w = h;
		h = d;
	}
	answer += w;
	return answer;
}