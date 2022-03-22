#include <iostream>
#include <string>
#include <algorithm>
#define MAX 1001
using namespace std;

int dp[MAX][MAX];

int main() {
	string src, dest;
	cin >> src >> dest;
	int result = 0;
	for (int i = 1; i <= src.size(); i++) {
		for (int j = 1; j <= dest.size(); j++) {
			if (src[i-1] == dest[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		result = max(result, dp[i][j]);
		}
	}
	cout << result << endl;
}