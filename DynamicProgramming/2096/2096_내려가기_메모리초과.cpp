#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 100001

int dp[MAX][3], arr[MAX][3];
int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i][0];
		dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + arr[i][2];
		dp[i][1] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]) + arr[i][1];
	}
	int max_num = max(max(dp[n][0], dp[n][1]), dp[n][2]);

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][0];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][2];
		dp[i][1] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]) + arr[i][1];
	}
	int min_num = min(min(dp[n][0], dp[n][1]), dp[n][2]);

	cout << max_num << endl << min_num << endl;
}