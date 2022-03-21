#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_HEALTH 101
using namespace std;

int health[21], delight[21];
int dp[21][MAX_HEALTH];

int N;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> health[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> delight[i];
	}
	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= MAX_HEALTH; j++) {
			if (j + health[i] < MAX_HEALTH) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + health[i]] + delight[i]);
			}
			else {
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			}
			result = max(dp[i][j], result);
		}
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= MAX_HEALTH; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << result << endl;
}