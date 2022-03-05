// 문제 개쓰레기 
#include<iostream>
#include<string>
using namespace std;

int n;													// 언더바 개수 카운팅 하기 위해 전역변수로 선언
void recursive(int x) {
	string under = "";
	for(int i = 0; i < n - x; i++) under += "____";		// n - x 만큼 언더바 사용
	cout << under << "\"재귀함수가 뭔가요?\"\n";
	if (x == 0) {										// 마지막 경우
		cout << under << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
	
	}
	else {												// 그 외의 경우
		cout << under << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
		cout << under << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";		
		cout << under << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
		recursive(x - 1);
	}
	cout << under << "라고 답변하였지.\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";

	recursive(n);
}