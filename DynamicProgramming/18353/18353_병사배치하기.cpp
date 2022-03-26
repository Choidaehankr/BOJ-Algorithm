#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> soldier;
int dp[2001];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		soldier.push_back(num);
	}
	reverse(soldier.begin(), soldier.end());
	fill(dp, dp + N, 1);
	int result = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (soldier[i] > soldier[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		result = max(result, dp[i]);
		}
	}
	cout << N - result << endl;
}