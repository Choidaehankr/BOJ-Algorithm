#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

int test_case, N;
int arr[3][MAX];
int dp[3][MAX];

long long solution() {
	dp[1][1] = arr[1][1];
	dp[2][1] = arr[2][1];
	for (int i = 2; i <= N; i++) {
		dp[1][i] = max(dp[2][i - 1], dp[2][i - 2]) + arr[1][i];
		dp[2][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[2][i];
	}
	return max(dp[1][N], dp[2][N]);
}

int main() {
	cin >> test_case; 
	while (test_case--) {
		cin >> N;
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> arr[i][j];
			}
		}
		cout << solution() << endl;
	}
}