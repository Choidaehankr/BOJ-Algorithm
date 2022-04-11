#include <iostream>
#include <algorithm>
using namespace std;

int min_dp[3], max_dp[3];
int N;

int main() {
	cin >> N;
	int num1, num2, num3, tmp1, tmp2;
	cin >> num1 >> num2 >> num3;
	max_dp[0] = min_dp[0] = num1;
	max_dp[1] = min_dp[1] = num2;
	max_dp[2] = min_dp[2] = num3;

	for (int i = 1; i < N; i++) {
		cin >> num1 >> num2 >> num3;
		tmp1 = max_dp[0], tmp2 = max_dp[2];
		max_dp[0] = max(max_dp[0], max_dp[1]) + num1;
		max_dp[2] = max(max_dp[1], max_dp[2]) + num3;
		max_dp[1] = max(max(tmp1, tmp2), max_dp[1]) + num2;

		tmp1 = min_dp[0], tmp2 = min_dp[2];
		min_dp[0] = min(min_dp[0], min_dp[1]) + num1;
		min_dp[2] = min(min_dp[1], min_dp[2]) + num3;
		min_dp[1] = min(min(tmp1, tmp2), min_dp[1]) + num2;
	}
	cout << max(max(max_dp[0], max_dp[1]), max_dp[2]) << endl;
	cout << min(min(min_dp[0], min_dp[1]), min_dp[2]) << endl;;
}