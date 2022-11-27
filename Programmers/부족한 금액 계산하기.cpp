using namespace std;

long long solution(int price, int money, int count)
{
	long long sum = (long long)price * count * (count + 1) / 2;	// 등차수열의 합
	return sum > money ? sum - money : 0;

}