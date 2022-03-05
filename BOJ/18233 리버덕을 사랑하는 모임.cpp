#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;

int N, P, E;
bool selected[20];	// 조합에서 선택된 애 누구인지 확인용
vector<pair<int, int>> member;	// 전체 멤버 최소값 최대값 받는 벡터
int minTotal, maxTotal;

void check(vector<int> recipient) {
	int distribute[20] = { 0 };		// 인형 어떻게 분배되는지 출력용
	int surplus = E - minTotal;		// 선택된 인간들의 수용 최소값을 전체 인형에서 빼줌
	for (int i = 0; i < recipient.size(); i++) {
		int x = member[recipient[i]].first;		// 가독성을 위한 x, y
		int y = member[recipient[i]].second;	// x에는 현재 사람의 최소값, y에는 최대값
		distribute[recipient[i]] = x;		// 분배는 일단 최소값을 넣어놓고 시작함

		if (surplus == 0) continue;		// 남은 인형이 0이면 이하 무시. break를 안하는 이유는 뒷 사람들의 최소값이 아직 저장되지 않았기 때문

		if (surplus > y - x) {			// 최대값 - 최소값과 잉여 인형 비교해서 잉여가 더 많으면 그 사람의 수용량 만큼 몰빵
			distribute[recipient[i]] += y - x;
			surplus -= y - x;
		}
		else {					// 잉여가 더 적으면 전부 다 줘버림. 이렇게 남은게 0이 되는경우가 있어서 19번째 줄로 시간을 줄임
			distribute[recipient[i]] += surplus;	
			surplus = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", distribute[i]);
	}
	printf("\n");
	exit(0);					// 더 이상 진행할 필요 없으므로 바로 종료
}

void comb(int start, int cnt) {
	if (cnt == P) {					// P개 만큼 선택된 경우. 기저조건
		vector<int> recipient;		// 받을사람 인덱스 넣어 보낼 벡터
		minTotal = 0, maxTotal = 0;	// 최소값 총 합과 최대값 총 합 저장할 변수
		for (int i = 0; i < N; i++) {
			if (selected[i]) {
				minTotal += member[i].first;	// 최소값 따로 더해줌
				maxTotal += member[i].second;	// 최대값 따로 더해줌
				recipient.push_back(i);			// 인덱스 저장
			}
		}
		if (minTotal <= E && maxTotal >= E) {	// 최소값 총 합과 최대값 총 합 사이에 E가 들어있으면 선택된 사람에서 E를 만들수 있음
			check(recipient);					// 선택된 사람 인덱스를 담은 벡터를 보냄
		}
		return;
	}

	for (int i = start; i < N; i++) {		// 그냥 조합
		selected[i] = true;
		comb(i + 1, cnt + 1);
		selected[i] = false;
	}
}

int main() {
	
	scanf("%d %d %d", &N, &P, &E);

	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		member.push_back({ x, y });
	}

	comb(0, 0);
	printf("%d\n", -1);		// 여기까지 왔으면 경우의 수 없었다는 뜻이므로 -1 출력
}