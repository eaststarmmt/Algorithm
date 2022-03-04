#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string input;
	cin >> input;
	vector<int> vec;
	for (int i = 0; i < input.size(); i++) {
		vec.push_back(input[i] - '0');
	}
	sort(vec.begin(), vec.end(), greater<int>());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
	}
	cout << "\n";
}