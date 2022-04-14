#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> profit;
unordered_map<string, string> refer;

void recordProfit(string name, int money) {
	if (name == "-")	// 본인이 마지막이면 탈출. 기저조건
		return;

	int sendMoney = money / 10;
	profit[name] += money - sendMoney;	// 1 미만이면 어차피 안빠짐
	if (sendMoney < 1)
		return;

	recordProfit(refer[name], sendMoney);

}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	vector<int> answer;
	for (int i = 0; i < enroll.size(); i++) {
		//refer.insert(make_pair(enroll[i], referral[i]));
		refer[enroll[i]] = referral[i];
	}	// map 세팅

	for (int i = 0; i < seller.size(); i++) {
		recordProfit(seller[i], amount[i] * 100);	// 한 개당 100원
	}
	for (int i = 0; i < enroll.size(); i++) {
		answer.push_back(profit[enroll[i]]);
	}
	return answer;
}