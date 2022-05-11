#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
#define WEIGHT 0
#define VALUE 1
using namespace std;

long long dp[101][MAX];
long long arr[101][2];
int N, K;
int main() {
	cin >> N >> K;
	vector<pair<int, int> > v;  // {Weight, Value}
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][WEIGHT] >> arr[i][VALUE];
	}
	long long result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (arr[i][WEIGHT] <= j) {
				if ((arr[i][VALUE] + dp[i - 1][j - arr[i][WEIGHT]]) > dp[i - 1][j]) {
					dp[i][j] = arr[i][VALUE] + dp[i - 1][j - arr[i][WEIGHT]];
				}
				else {
					dp[i][j] = dp[i-1][j];
				}
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
			result = max(result, dp[i][j]);
		}
	}
	cout << result << endl;
}